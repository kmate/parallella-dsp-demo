module Main where

import qualified Prelude as P
import System.IO

import Zeldspar.Multicore


type RealSamples     = Vector (Data Float)
type ComplexSamples  = Vector (Data (Complex Float))
type Twiddles        = Vector (Data (Complex Float))


flipFlop :: Storable a
         => (Store a, Store a)
         -> [a -> a]
         -> CoreZ a a
flipFlop (a, b) fs = do
  let fs' = P.zip fs (P.cycle [(a, b), (b, a)])
      go _ (f, (src, dst)) = do
          input <- unsafeFreezeStore src
          let output = f input
          writeStore dst output
          return output
  loop $ do
    input <- receive
    lift $ writeStore a input
    output <- lift $ foldM go input fs'
    emit output


--------------------------------------------------------------------------------
-- Bit reversal
--------------------------------------------------------------------------------

-- | Rotates the 'k + 1' LSB bits right with 1.
rotBit :: Index -> Data Index -> Data Index
rotBit k i = lefts .|. rights
  where
    k'     = i2n $ value k
    ir     = i .>>. 1
    rights = ir .&. oneBits k'
    lefts  = (((ir .>>. k') .<<. 1) .|. (i .&. 1)) .<<. k'

-- | Permute the vector by applying 'rotBit k' on its indices.
riffle :: Index -> Vector (Data a) -> Vector (Data a)
riffle k = permute (const $ rotBit k)

-- | Generates parallel bit reversal of a vector with length 'n'.
bitRev :: PrimType a => Length -> [ Vector (Data a) -> Vector (Data a) ]
bitRev n = [ riffle k | k <- [1..P.floor (logBase 2 $ P.fromIntegral n) - 1] ]


--------------------------------------------------------------------------------
-- "Pull-style" parallel FFT
--------------------------------------------------------------------------------

fft :: Length -> CoreZ ComplexSamples ComplexSamples
fft = fftBase False

ifft :: Length -> CoreZ ComplexSamples ComplexSamples
ifft = fftBase True

-- Fusion of a whole FFT is not possible for 'n' = 1024,
-- so we store the internal result after each stage to the same store.
fftBase :: Bool ->  Length -> CoreZ ComplexSamples ComplexSamples
fftBase inv n = do
  core <- lift $ fftCore inv n
  let rev = bitRev n
      n'  = P.fromIntegral n
  a <- lift $ newStore n'
  b <- lift $ newStore n'
  flipFlop (a, b) (core P.++ rev)

-- | Generates all 'ilog2 n' FFT/IFFT stages for a sample vector.
fftCore :: Bool -> Length -> CoreComp [ ComplexSamples -> ComplexSamples ]
fftCore inv n = do
  twids <- precompute (twids inv n)
  let n' = P.floor (logBase 2 $ P.fromIntegral n) - 1
  return [ step twids n k | k <- P.reverse [0..n'] ]

-- | Performs the 'k'th FFT/IFFT stage on a sample vector.
step :: Twiddles -> Length -> Length -> ComplexSamples -> ComplexSamples
step twids n k v = Indexed (value n) ixf
  where
    ixf i = testBit i (i2n k') ? ((twids ! t) * (b - a)) $ (a + b)
      where
        a  = v ! i
        b  = v ! (i `xor` (1 .<<. i2n k'))
        k' = value k
        t  = lsbs (i2n $ value n') (i .<<. value p)
        p  = P.fromIntegral $ n' - k
        n' = P.floor (logBase 2 $ P.fromIntegral n) - 1

twids :: Bool -> Length -> Twiddles
twids inv n = Indexed (value (n `P.div` 2)) ixf
  where
    scale = if inv then 1 else -1
    ixf i = polar 1 (π * i2n i * value (scale * 2 P./ P.fromIntegral n))

-- | Indicates whether the 'i'th bit of 'a' is set.
testBit :: (Bits a, Num a, PrimType a) => Data a -> Data Index -> Data Bool
testBit a i = a .&. (1 .<<. i2n i) /= 0


--------------------------------------------------------------------------------
-- DSP implementation
--------------------------------------------------------------------------------

hann :: Data Length -> RealSamples
hann width = Indexed width
           $ \k -> -0.5 * cos(2 * π * (i2n k) / (i2n width)) + 0.5

window :: CoreZ RealSamples RealSamples
window = do
  hann <- lift $ precompute (hann fftSize)
  loop $ do
    input <- receive
    emit $ zipWith (*) input hann

interleave :: CoreZ RealSamples ComplexSamples
interleave = loop $ do
  input <- receive
  emit $ map (flip complex 0) input

zeroes :: Data Length -> RealSamples
zeroes l = Indexed l $ const 0

analyze :: CoreZ ComplexSamples ComplexSamples
analyze = do
  lastPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    lastPhase <- lift $ unsafeFreezeStore lastPhaseS
    let result = Indexed numPosBins ixf
        ixf k = (complex magn freq, phs)
          where
            -- compute magnitude and phase
            magn  = 2 * magnitude (input ! k)
            phs   = phase (input ! k)
            -- compute phase difference
            diff  = phs - lastPhase ! k
            -- subtract expected phase difference
            expct = diff - i2n k * expectedDiff
            -- get deviation from bin frequency from the ±π interval
            deriv = (i2n overlap * expct) / (2 * π)
            -- compute the k-th partials' true frequency
            freq  = (i2n k + deriv) * freqPerBin
    let (output, lastPhase') = unzip result
    emit output  -- emit before store!
    lift $ writeStore lastPhaseS lastPhase'

mulImag :: (Num a, PrimType a, PrimType (Complex a))
        => Data (Complex a) -> Data a -> Data (Complex a)
mulImag c n = complex (realPart c) (n * imagPart c)

shiftPitch :: CoreZ ComplexSamples ComplexSamples
shiftPitch = loop $ do
  input <- receive
  output <- lift $ do
    buffer <- newArr numPosBins
    for (0, 1, Excl numPosBins) $ \k -> do
      let index = round $ i2n k * pitchShift
          value = (index < numPosBins) ? ((input ! k) `mulImag` pitchShift) $ 0
      setArr index value buffer
    unsafeFreezeVec numPosBins buffer
  emit output

synthetize :: CoreZ ComplexSamples ComplexSamples
synthetize = do
  sumPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    sumPhase <- lift $ unsafeFreezeStore sumPhaseS
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
    emit output  -- emit before store!
    lift $ writeStore sumPhaseS sumPhase'

zeroNegBins :: CoreZ ComplexSamples ComplexSamples
zeroNegBins = loop $ do
  input <- receive
  emit $ Indexed fftSize $ \i -> (i <= numPosBins) ? (input ! i) $ 0

accumulate :: CoreZ ComplexSamples RealSamples
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
fftSize' :: Length
fftSize' = 1024

overlap :: Data Length
overlap = 4

sampleRate :: Data Float
sampleRate = 44100

-- Derived constants
stepSize :: Data Length
stepSize = fftSize `div` overlap

fftSize :: Data Length
fftSize = value fftSize'

numPosBins' :: Length
numPosBins' = fftSize' `P.div` 2 + 1

numPosBins :: Data Length
numPosBins = value numPosBins'

freqPerBin :: Data Float
freqPerBin = sampleRate / i2n fftSize

expectedDiff :: Data Float
expectedDiff = 2 * π * i2n stepSize / i2n fftSize


mainProgram :: Multicore ()
mainProgram = do
  let chanSize = 1 `ofLength` fftSize'
      halfChanSize = 1 `ofLength` numPosBins'
  onHost $ liftHost $ do
    addInclude "\"processor.h\""
    callProc "setup_queues" []
  translatePar ((window >>> interleave)      `on` 0 |>>chanSize>>|
                (fft 1024)                   `on` 1 |>>chanSize>>|
                analyze                      `on` 2 |>>halfChanSize>>|
                shiftPitch                   `on` 3 |>>halfChanSize>>|
                (synthetize >>> zeroNegBins) `on` 4 |>>chanSize>>|
                (ifft 1024)                  `on` 5 |>>chanSize>>|
                (accumulate >>> window)      `on` 6)
    (do buffer :: Arr Float <- newArr fftSize
        hasMore :: Data Bool <- liftHost $ callFun "receive_samples" [ arrArg buffer ]
        input <- unsafeFreezeVec fftSize buffer
        return (input, hasMore))
    chanSize
    (\output -> do
        Manifest bufferSize buffer' <- fromPull output
        buffer <- unsafeThawArr buffer'
        needsMore :: Data Bool <- liftHost $ callFun "emit_samples" [ arrArg buffer ]
        return needsMore)
    chanSize
  onHost $ liftHost $ callProc "teardown_queues" []


main = do
    let outFile = "gen/processor.c"
    h <- openFile outFile WriteMode
    hPutStrLn h $ compile mainProgram
    hClose h
    putStrLn $ "x86 source generated: " P.++ show outFile

    let modules = compileAll `onParallella` mainProgram
    outFiles <- forM modules $ \(name, contents) -> do
        let name' = if name P.== "main" then "host" else name
            path  = "gen/" P.++ name' P.++ ".c"
        writeFile path contents
        return path
    putStrLn $ "Epiphany sources generated: " P.++ show outFiles
