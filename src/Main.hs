module Main where

import Prelude ((++), floor, foldl1, fromIntegral, reverse)
import System.IO

import Zeldspar
import Zeldspar.Parallel


type Samples  = Vector (Data (Complex Float))
type Twiddles = Vector (Data (Complex Float))


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

-- | Bit reversal of a vector with length 'n'.
bitRev :: PrimType a => Length -> Zun (Vector (Data a)) (Vector (Data a)) ()
bitRev n = foldl1 (>>>) [ riffle (value k) >>> loop store | k <- [1..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1

-- | Parallel bit reversal of a vector with length 'n'.
bitRevPar :: PrimType a => Length -> ParZun (Vector (Data a)) (Vector (Data a)) ()
bitRevPar n = foldl1 (\a b -> a |>>10`ofLength`value n>>| b)
            [ liftP $ riffle $ value k | k <- [1..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1


--------------------------------------------------------------------------------
-- "Pull-style" FFT
--------------------------------------------------------------------------------

fft :: Length -> Zun Samples Samples ()
fft n = fftCore n False >>> bitRev n

ifft :: Length -> Zun Samples Samples ()
ifft n = fftCore n True >>> bitRev n

fftPar :: Length -> ParZun Samples Samples ()
fftPar n = fftCorePar n False |>>10`ofLength`value n>>| bitRevPar n

-- | Performs all 'ilog2 n' FFT/IFFT stages on a sample vector.
fftCore :: Length -> Bool -> Zun Samples Samples ()
fftCore n inv = foldl1 (>>>) [ step inv (value k) >>> loop store
                             | k <- Prelude.reverse [0..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1

fftCorePar :: Length -> Bool -> ParZun Samples Samples ()
fftCorePar n inv = foldl1 (\a b -> a |>>10`ofLength`value n>>| b)
                 [ liftP $ step inv $ value k | k <- Prelude.reverse [0..n'] ]
  where
    n' = floor (logBase 2 $ fromIntegral n) - 1

-- | Performs the 'k'th FFT/IFFT stage on a sample vector.
step :: Bool -> Data Length -> Zun Samples Samples ()
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

hann :: Data Length -> Vector (Data Float)
hann width = Indexed width
           $ \k -> -0.5 * cos(2 * π * (i2n k) / (i2n width)) + 0.5

window :: Zun (Vector (Data Float)) (Vector (Data Float)) ()
window = loop $ do
  input <- receive
  emit $ zipWith (*) input (hann fftSize)

interleave :: Zun (Vector (Data Float)) (Vector (Data (Complex Float))) ()
interleave = loop $ do
  input <- receive
  emit $ map (flip complex 0) input

backToCircle :: Data Float -> Run (Data Float)
backToCircle v = do
  tmp <- initRef v
  while ((>π) <$> getRef tmp) ((+(-(π * 2))) <$> getRef tmp >>= setRef tmp)
  while ((<(-π)) <$> getRef tmp) ((+(π * 2)) <$> getRef tmp >>= setRef tmp)
  getRef tmp

analyze :: Zun (Vector (Data (Complex Float))) (Vector (Data (Complex Float))) ()
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
      tmp'' <- backToCircle tmp'
      let deriv = (i2n overlap * tmp'') / (2 * π)
          freq  = (i2n k + deriv) * freqPerBin
      setArr k (complex magn freq) buffer
    buffer' <- lift $ unsafeFreezeArr buffer
    let output = toPull $ Manifest bufferSize buffer'
    emit output

mulImag :: (Num a, PrimType a, PrimType (Complex a))
        => Data (Complex a) -> Data a -> Data (Complex a)
mulImag c n = complex (realPart c) (n * imagPart c)

shiftPitch :: Zun (Vector (Data (Complex Float))) (Vector (Data (Complex Float))) ()
shiftPitch = loop $ do
  input <- receive
  buffer <- lift $ newArr numPosBins
  lift $ for (0, 1, Excl numPosBins) $ \k -> do
    let index = round $ i2n k * pitchShift
        value = (index < numPosBins) ? ((input ! k) `mulImag` pitchShift) $ (0)
    typedIxRef <- initRef index
    index' <- getRef typedIxRef
    setArr index' value buffer
  buffer' <- lift $ unsafeFreezeArr buffer
  let output = toPull $ Manifest bufferSize buffer'
  emit output

-- TODO: reimplement wrapped functionality in Zeldspar
-- cWrapper :: Zun (Vector (Data (Complex Float))) (Vector (Data Float)) ()
cWrapper :: Zun (Vector (Data (Complex Float))) (Vector (Data (Complex Float))) ()
cWrapper = do
  lift $ addInclude "\"c_processor.h\""
  loop $ do
    input <- receive
    Manifest bufferSize buffer' <- lift $ fromPull input
    inBuffer <- lift $ unsafeThawArr buffer'
    outBuffer <- lift $ newArr bufferSize
    lift $ callProc "smbPitchShift" [ valArg pitchShift
                                    , arrArg inBuffer
                                    , arrArg outBuffer ]
    buffer'' <- lift $ unsafeFreezeArr outBuffer
    let output = toPull $ Manifest bufferSize buffer''
    emit output

zeroNegBins :: Zun (Vector (Data (Complex Float))) (Vector (Data (Complex Float))) ()
zeroNegBins = loop $ do
  input <- receive
  emit $ Indexed fftSize $ \i -> (i <= numPosBins) ? (input ! i) $ 0

accumulate :: Zun (Vector (Data (Complex Float))) (Vector (Data Float)) ()
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
  translatePar (liftP (window >>> interleave >>> (fft 1024) >>> analyze >>>
                       cWrapper >>> shiftPitch >>>
                       zeroNegBins >>> (ifft 1024) >>> accumulate >>> window))
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
