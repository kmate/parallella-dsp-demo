module Main where

import Prelude ((++), floor, foldl1, fromIntegral, reverse)
import System.IO

import Zeldspar
import Zeldspar.Parallel


type RealSamples     = Vector (Data Float)
type ComplexSamples  = Vector (Data (Complex Float))
type Twiddles        = Vector (Data (Complex Float))


--------------------------------------------------------------------------------
-- Bit reversal
--------------------------------------------------------------------------------

-- | Rotates the 'k + 1' LSB bits right with 1.
rotBit :: Data Index -> Data Index -> Data Index
rotBit k i = lefts .|. rights
  where
    k'     = i2n k
    ir     = i .>>. 1
    rights = ir .&. oneBits k'
    lefts  = (((ir .>>. k') .<<. 1) .|. (i .&. 1)) .<<. k'

-- | Permute the vector by applying 'rotBit k' on its indices.
riffle :: Data Index -> Zun (Vector (Data a)) (Vector (Data a)) ()
riffle k = loop $ receive >>= emit . permute (const $ rotBit k)

-- | Parallel bit reversal of a vector with length 'n'.
bitRevPar :: PrimType a
          => Length  -- ^ Length of a vector
          -> Length  -- ^ Maximum number of vectors on internal channels
          -> ParZun (Vector (Data a)) (Vector (Data a)) ()
bitRevPar n m = foldl1 (\a b -> a |>>value m`ofLength`value n>>| b)
            [ liftP $ riffle $ value k | k <- [1..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1


--------------------------------------------------------------------------------
-- "Pull-style" parallel FFT
--------------------------------------------------------------------------------

fftPar :: Length -> Length -> ParZun ComplexSamples ComplexSamples ()
fftPar = fftBase False

ifftPar :: Length -> Length -> ParZun ComplexSamples ComplexSamples ()
ifftPar = fftBase True

fftBase :: Bool -> Length -> Length -> ParZun ComplexSamples ComplexSamples ()
fftBase inv n m = fftCorePar inv n m |>>value m`ofLength`value n>>| bitRevPar n m

-- | Performs all 'ilog2 n' FFT/IFFT stages on a sample vector.
fftCorePar :: Bool -> Length -> Length -> ParZun ComplexSamples ComplexSamples ()
fftCorePar inv n m = foldl1 (\a b -> a |>>value m`ofLength`value n>>| b)
                   [ liftP $ step inv $ value k | k <- Prelude.reverse [0..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1

-- | Performs the 'k'th FFT/IFFT stage on a sample vector.
step :: Bool -> Data Length -> Zun ComplexSamples ComplexSamples ()
step inv k = loop $ do
    v <- receive
    let ixf i = testBit i k ? (twid * (b - a)) $ (a + b)
          where
            k'   = i2n k
            a    = v ! i
            b    = v ! (i `xor` k2)
            twid = polar 1 ((if inv then π else -π) * i2n (lsbs k' i) / i2n k2)
            k2   = 1 .<<. k'
    emit $ Indexed (length v) ixf

-- | Indicates whether the 'i'th bit of 'a' is set.
testBit :: (Bits a, Num a, PrimType a) => Data a -> Data Index -> Data Bool
testBit a i = a .&. (1 .<<. i2n i) /= 0


--------------------------------------------------------------------------------
-- Temporary C wrapper in Zeldspar
--------------------------------------------------------------------------------

hann :: Data Length -> RealSamples
hann width = Indexed width
           $ \k -> -0.5 * cos(2 * π * (i2n k) / (i2n width)) + 0.5

window :: Zun RealSamples RealSamples ()
window = loop $ do
  input <- receive
  emit $ zipWith (*) input (hann fftSize)

interleave :: Zun RealSamples ComplexSamples ()
interleave = loop $ do
  input <- receive
  emit $ map (flip complex 0) input

analyze :: Zun ComplexSamples ComplexSamples ()
analyze = do
  lastPhase <- lift $ newArr numPosBins
  loop $ do
    input <- receive
    buffer <- lift $ newArr numPosBins
    lift $ for (0, 1, Excl numPosBins) $ \k -> do
      lphs :: Data Float <- getArr k lastPhase
      let magn  = 2 * magnitude (input ! k)
          phs   = phase (input ! k)
          tmp   = phs - lphs
      setArr k phs lastPhase
      let tmp'  = tmp - i2n k * expectedDiff
      tmp'' <- callFun "clampPhase" [ valArg tmp' ]
      let deriv = (i2n overlap * tmp'') / (2 * π)
          freq  = (i2n k + deriv) * freqPerBin
      setArr k (complex magn freq) buffer
    buffer' <- lift $ unsafeFreezeArr buffer
    let output = toPull $ Manifest bufferSize buffer'
    emit output

mulImag :: (Num a, PrimType a, PrimType (Complex a))
        => Data (Complex a) -> Data a -> Data (Complex a)
mulImag c n = complex (realPart c) (n * imagPart c)

shiftPitch :: Zun ComplexSamples ComplexSamples ()
shiftPitch = loop $ do
  input <- receive
  buffer <- lift $ newArr numPosBins
  lift $ for (0, 1, Excl numPosBins) $ \k -> do
    let index = round $ i2n k * pitchShift
        value = (index < numPosBins) ? ((input ! k) `mulImag` pitchShift) $ (0)
    -- FIXME: We need an explicit integer variable here as the index expression
    -- is a call to `round`, which returns a double. Then the C compiler
    -- complains about a non-integer array subscript expression.
    typedIxRef <- initRef index
    index' <- getRef typedIxRef
    setArr index' value buffer
  buffer' <- lift $ unsafeFreezeArr buffer
  let output = toPull $ Manifest bufferSize buffer'
  emit output

synthetize :: Zun ComplexSamples ComplexSamples ()
synthetize = do
  sumPhase <- lift $ newArr numPosBins
  loop $ do
    input <- receive
    buffer <- lift $ newArr numPosBins
    lift $ for (0, 1, Excl numPosBins) $ \k -> do
      sphs :: Data Float <- getArr k sumPhase
      let magn  = realPart (input ! k)
          tmp   = imagPart (input ! k)
          tmp'  = 2 * π * ((tmp - i2n k * freqPerBin) / freqPerBin) / i2n overlap
          tmp'' = tmp' + i2n k * expectedDiff
          phs   = sphs + tmp''
      setArr k phs sumPhase
      setArr k (polar magn phs) buffer
    buffer' <- lift $ unsafeFreezeArr buffer
    let output = toPull $ Manifest bufferSize buffer'
    emit output

zeroNegBins :: Zun ComplexSamples ComplexSamples ()
zeroNegBins = loop $ do
  input <- receive
  emit $ Indexed fftSize $ \i -> (i <= numPosBins) ? (input ! i) $ 0

accumulate :: Zun ComplexSamples RealSamples ()
accumulate = loop $ do
  input <- receive
  emit $ map ((/ i2n (fftSize * overlap)) . realPart) input


--------------------------------------------------------------------------------
-- Main program and constants
--------------------------------------------------------------------------------

-- Value 1 means no shifting. 2 is one octave up, 0.5 is one octave down.
pitchShift :: Data Float
pitchShift = 2

-- Needed to be in sync with C and JS code!
bufferSize :: Data Length
bufferSize = 1024

fftSize :: Data Length
fftSize = 1024

overlap :: Data Length
overlap = 4

sampleRate :: Data Float
sampleRate = 44100

-- Derived constants
stepSize :: Data Length
stepSize = fftSize `div` overlap

numPosBins :: Data Length
numPosBins = fftSize `div` 2 + 1

freqPerBin :: Data Float
freqPerBin = sampleRate / i2n fftSize

expectedDiff :: Data Float
expectedDiff = 2 * π * i2n stepSize / i2n fftSize


mainProgram :: Run ()
mainProgram = do
  addInclude "\"processor.h\""
  callProc "setup_queues" []
  let chanSize = 10 `ofLength` bufferSize
  translatePar ((window >>> interleave)      |>>chanSize>>|
                (fftPar 1024 10)             |>>chanSize>>|
                analyze                      |>>chanSize>>|
                shiftPitch                   |>>chanSize>>|
                (synthetize >>> zeroNegBins) |>>chanSize>>|
                (ifftPar 1024 10)            |>>chanSize>>|
                (accumulate >>> window))
    (do buffer :: Arr Float <- newArr bufferSize
        hasMore :: Data Bool <- callFun "receive_samples" [ arrArg buffer ]
        input <- unsafeFreezeVec bufferSize buffer
        return (input, hasMore))
    chanSize
    (\output -> do
        Manifest bufferSize buffer' <- fromPull output
        buffer <- unsafeThawArr buffer'
        needsMore :: Data Bool <- callFun "emit_samples" [ arrArg buffer ]
        return needsMore)
    chanSize
  callProc "teardown_queues" []


main = do
    let outFile = "gen/processor.c"
    h <- openFile outFile WriteMode
    hPutStrLn h $ compile mainProgram
    hClose h
    putStrLn $ "Source generated: " ++ show outFile
