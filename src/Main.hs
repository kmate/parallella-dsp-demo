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

{-  FIXME: Unfortunately, this function could not be implemented effectively.
    See the following C implemention:

    float clampPhase(float phase) {
      int q = phase / FELD_PI;
      if (q >= 0) {
        q += q & 1;
      } else {
        q -= q & 1;
      }
      phase -= FELD_PI * (double)q;
      return phase;
    }

    The current implementation is an expression generator, that is only able to
    recover values in range [-nπ..nπ], instantiated with n = 8.
-}
clampPhase :: Data Float -> Data Float
clampPhase = clampPhase' 8

clampPhase' :: Length -> Data Float -> Data Float
clampPhase' 0 phase = phase
clampPhase' n phase = (phase < -π) ?
  (clampPhase' (n - 1) (phase + 2 * π)) $
  ((phase > π) ?
     (clampPhase' (n - 1) (phase - 2 * π)) $
     phase)

zeroes :: Data Length -> RealSamples
zeroes l = Indexed l $ const 0

analyze :: Zun ComplexSamples ComplexSamples ()
analyze = do
  lastPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    lastPhase <- lift $ readStore lastPhaseS
    let result = Indexed numPosBins ixf
        ixf k = (complex magn freq, phs)
          where
            -- compute magnitude and phase
            magn  = 2 * magnitude (input ! k)
            phs   = phase (input ! k)
            -- compute phase difference
            diff  = phs - lastPhase ! k
            -- subtract expected phase difference
            expct = clampPhase (diff - i2n k * expectedDiff)
            -- get deviation from bin frequency from the ±π interval
            deriv = (i2n overlap * expct) / (2 * π)
            -- compute the k-th partials' true frequency
            freq  = (i2n k + deriv) * freqPerBin
    let (output, lastPhase') = unzip result
    lift $ writeStore lastPhaseS lastPhase'
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
  let output = toPull $ Manifest numPosBins buffer'
  emit output

synthetize :: Zun ComplexSamples ComplexSamples ()
synthetize = do
  sumPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    sumPhase <- lift $ readStore sumPhaseS
    let result = Indexed numPosBins ixf
        ixf k = (polar magn phs, phs)
          where
            -- get magnitude and true frequency
            magn  = realPart (input ! k)
            freq  = imagPart (input ! k)
            -- subtract bin mid frequency
            mfreq = freq - i2n k * freqPerBin
            -- get bin deviation from freq deviation
            deriv = mfreq / freqPerBin
            -- take overlap into account
            olap  = 2 * π * deriv / i2n overlap
            -- add the overlap phase advance back in
            expct = olap + i2n k * expectedDiff
            -- accumulate delta phase to get bin phase
            phs   = (sumPhase ! k) + expct
    let (output, sumPhase') = unzip result
    lift $ writeStore sumPhaseS sumPhase'
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

-- Needed to be in sync with C the code!
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
  let chanSize = 10 `ofLength` fftSize
      halfChanSize = 10 `ofLength` numPosBins
  translatePar ((window >>> interleave)      |>>chanSize>>|
                (fftPar 1024 10)             |>>chanSize>>|
                analyze                      |>>halfChanSize>>|
                shiftPitch                   |>>halfChanSize>>|
                (synthetize >>> zeroNegBins) |>>chanSize>>|
                (ifftPar 1024 10)            |>>chanSize>>|
                (accumulate >>> window))
    (do buffer :: Arr Float <- newArr fftSize
        hasMore :: Data Bool <- callFun "receive_samples" [ arrArg buffer ]
        input <- unsafeFreezeVec fftSize buffer
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
