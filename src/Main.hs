module Main where

import qualified Prelude as P
import qualified Data.Bits as P
import Data.Complex (mkPolar)
import System.IO

import Zeldspar.Multicore


type RealSamples        = DPull Float
type ComplexSampleArr   = Arr (Complex Float)
type ComplexSamples     = DPull (Complex Float)
type ComplexSampleStore = Store ComplexSamples
type Twiddles           = DPull (Complex Float)


--------------------------------------------------------------------------------
-- Utilities
--------------------------------------------------------------------------------

compileTimeVec :: (PrimType a, MonadComp m)
               => Length
               -> (Index -> a)
               -> m (DPull a)
compileTimeVec len ixf = do
  arr <- initArr [ ixf i | i <- [0..len-1] ]
  unsafeFreezeVec (value len) arr

processArr :: PrimType a
           => (Arr a -> CoreComp ())
           -> CoreZ (Store (DPull a)) (Store (DPull a)) ()
processArr f = loop $ do
  s@(Store (_,arr)) <- receive
  lift $ f arr
  emit s

mulImag :: (Num a, PrimType a, PrimType (Complex a))
        => Data (Complex a) -> Data a -> Data (Complex a)
mulImag c n = complex (realPart c) (n * imagPart c)


--------------------------------------------------------------------------------
-- Size-optimized approximations of complex math library
--------------------------------------------------------------------------------

magnitude' :: (RealFloat a, PrimType a, PrimType (Complex a))
           => Data (Complex a) -> Data a
magnitude' c = a * (max re im) + b * (min re im)
  where
    re = abs $ realPart c
    im = abs $ imagPart c
    a = 15 / 16
    b = 15 / 32

phase' :: (RealFloat a, PrimType a, PrimType (Complex a))
       => Data (Complex a) -> Data a
phase' c = (y < 0) ? (-angle) $ angle
  where
    x = realPart c
    y = imagPart c
    c1 = pi / 4
    c2 = 3 * c1
    ay = abs y + 1e-10
    angle = (x >= 0)
      ? (c1 - c1 * ((x - ay) / (x + ay)))
      $ (c2 - c1 * ((x + ay) / (ay - x)))

polar' :: (RealFloat a, PrimType a, PrimType (Complex a))
       => Data a -> Data a -> Data (Complex a)
polar' m p = complex re im
  where
    re = m * cos' p
    im = m * sin' p
    sin' x = cos' (pi / 2 - x)
    cos' x = share (wrap x) (flip horner [c0,0,c2,0,c4,0,c6,0,c8,0,c10,0,c12])
      where
        wrap   x = x - 2 * pi * round (x / (2 * pi) + 0.5)
        horner x = P.foldr (\a b -> a + b * x) 0
        c0  =  9.99999992290827491711e-01
        c2  = -4.99999917728614591900e-01
        c4  =  4.16665243677686230461e-02
        c6  = -1.38879704270452054154e-03
        c8  =  2.47734245730930250260e-05
        c10 = -2.71133771940801138503e-07
        c12 =  1.73691489450821293670e-09


--------------------------------------------------------------------------------
-- Bit reversal
--------------------------------------------------------------------------------

bitRevArr :: (MonadComp m, PrimType a) => Length -> Arr a -> m ()
bitRevArr n arr = do
  let m = value $ P.floor (logBase 2 $ P.fromIntegral n)
  for (0, 1, Excl $ value n) $ \a -> do
    br <- initRef a
    modifyRef br (\b -> ((b .&. 0xaaaaaaaa) .>>. 1) .|. ((b .&. 0x55555555) .<<. 1))
    modifyRef br (\b -> ((b .&. 0xcccccccc) .>>. 2) .|. ((b .&. 0x33333333) .<<. 2))
    modifyRef br (\b -> ((b .&. 0xf0f0f0f0) .>>. 4) .|. ((b .&. 0x0f0f0f0f) .<<. 4))
    modifyRef br (\b -> ((b .&. 0xff00ff00) .>>. 8) .|. ((b .&. 0x00ff00ff) .<<. 8))
    modifyRef br (\b -> ((b .>>. 16) .|. (b .<<. 16)) .>>. (32 - m))
    b <- unsafeFreezeRef br
    iff (b > a)
      (do av :: Data a <- getArr a arr
          bv :: Data a <- getArr b arr
          setArr a bv arr
          setArr b av arr)
      (return ())

bitRev :: PrimType a => Length -> CoreZ (Store (DPull a)) (Store (DPull a)) ()
bitRev n = processArr (bitRevArr n)


--------------------------------------------------------------------------------
-- "Pull-style" parallel FFT
--------------------------------------------------------------------------------

fft :: Length -> [CoreId] -> MulticoreZ ComplexSampleStore ComplexSampleStore ()
fft = fftBase False

ifft :: Length -> [CoreId] -> MulticoreZ ComplexSampleStore ComplexSampleStore ()
ifft = fftBase True

fftBase :: Bool -> Length -> [CoreId] -> MulticoreZ ComplexSampleStore ComplexSampleStore ()
fftBase inv n cores = (P.foldl1 connect fftProgs) `connect` (bitRev n `on` forRev)
  where
    chanSize = 1 `ofLength` n
    forFFT = P.init cores
    forRev = P.last cores
    numStages = P.floor (logBase 2 $ P.fromIntegral n)
    stages = [0..numStages - 1]
    groups = distribute' stages (P.length forFFT)
    fftTask stages = processArr $ \arr -> do
      twids <- calcTwids inv n
      forM_ stages $ \k -> fftStageArr twids n k arr
    fftTasks = P.map fftTask groups
    fftProgs = P.zipWith on fftTasks forFFT
    connect a b = a |>>chanSize>>| b

distribute' :: [a] -> Int -> [[a]]
distribute' stages ncores = P.reverse $ P.snd $ P.foldl chop (stages, []) sizes
  where
    chop (l, r) s = let (a, b) = P.splitAt s l in (b, a:r)
    sizes = P.replicate rem (quot + 1) P.++ P.replicate (ncores - rem) quot
    (quot, rem) = ntasks `P.quotRem` ncores
    ntasks = P.length stages

fftStageArr :: Twiddles -> Length -> Index -> ComplexSampleArr -> CoreComp ()
fftStageArr twids n k arr = do
  let numStages = P.floor (logBase 2 $ P.fromIntegral n)
      rounds    = value $ 1 `P.shiftL` P.fromIntegral k
      bflies    = value $ n `P.shiftR` (P.fromIntegral k + 1)
      itemStep  = bflies
      twidStep  = rounds
  for (0, 1, Excl rounds) $ \r -> do
    tIxr <- initRef (0 :: Data Word32)
    for (0, 1, Excl bflies) $ \b -> do
      aIx <- force $ i2n r * 2 * bflies + b
      bIx <- force $ aIx + itemStep
      tIx <- getRef tIxr
      modifyRef tIxr (+(twidStep :: Data Word32))
      a <- getArr aIx arr
      b <- getArr bIx arr
      setArr aIx (a + b) arr
      setArr bIx ((a - b) * twids ! tIx) arr

calcTwids :: MonadComp m => Bool -> Length -> m Twiddles
calcTwids inv n = compileTimeVec len ixf
  where
    len = n `P.div` 2
    scale = if inv then 1 else -1
    ixf i = mkPolar 1 (pi * P.fromIntegral i * scale * 2 P./ P.fromIntegral n)


--------------------------------------------------------------------------------
-- DSP implementation
--------------------------------------------------------------------------------

hann :: Length -> Index -> Float
hann size k = -0.5 * cos(2 * pi * P.fromIntegral k / P.fromIntegral size) + 0.5

window :: CoreZ RealSamples RealSamples ()
window = do
  hann <- lift $ compileTimeVec fftSize' (hann fftSize')
  loop $ do
    input <- receive
    emit $ zipWith (*) input hann

interleave :: CoreZ RealSamples ComplexSamples ()
interleave = loop $ do
  input <- receive
  emit $ fmap (flip complex 0) input

zeroes :: Data Length -> RealSamples
zeroes l = Pull l $ const 0

analyze :: CoreZ ComplexSamples ComplexSamples ()
analyze = do
  lastPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    lastPhase <- lift $ unsafeFreezeStore lastPhaseS
    let result = Pull numPosBins ixf
        ixf k = (complex magn freq, phs)
          where
            -- compute magnitude and phase
            magn  = 2 * magnitude' (input ! k)
            phs   = phase' (input ! k)
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

shiftPitch :: CoreZ ComplexSamples ComplexSampleStore ()
shiftPitch = loop $ do
  input <- receive
  output <- lift $ do
    buffer <- initArr (P.replicate (P.fromIntegral numPosBins') 0)
    lenRef <- initRef numPosBins
    for (0, 1, Excl numPosBins) $ \k -> do
      index <- force $ round $ i2n k * pitchShift
      let value = (index < numPosBins) ? ((input ! k) `mulImag` pitchShift) $ 0
      setArr index value buffer
    return $ Store (lenRef, buffer)
  emit output

synthetize :: CoreZ ComplexSamples ComplexSamples ()
synthetize = do
  sumPhaseS <- lift $ initStore (zeroes numPosBins)
  loop $ do
    input <- receive
    sumPhase <- lift $ unsafeFreezeStore sumPhaseS
    let result = Pull numPosBins ixf
        ixf k = (polar' magn phs, phs)
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

zeroNegBins :: CoreZ ComplexSamples ComplexSamples ()
zeroNegBins = loop $ do
  input <- receive
  emit $ Pull fftSize $ \i -> (i <= numPosBins) ? (input ! i) $ 0

accumulate :: CoreZ ComplexSamples RealSamples ()
accumulate = loop $ do
  input <- receive
  emit $ fmap ((/ i2n (fftSize * overlap)) . realPart) input


--------------------------------------------------------------------------------
-- Main program and constants
--------------------------------------------------------------------------------

-- Value 1 means no shifting. 2 is one octave up, 0.5 is one octave down.
pitchShift :: Data Float
pitchShift = 2

-- Needed to be in sync with C the code!
fftSize' :: Length
fftSize' = 512

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
  runZ ((window >>> interleave)      `on` 0  |>>chanSize>>|
        fft  fftSize'            [1,2,3,7,6] |>>chanSize>>|
        analyze                      `on` 5  |>>halfChanSize>>|
        shiftPitch                   `on` 4  |>>halfChanSize>>|
        (synthetize >>> zeroNegBins) `on` 8  |>>chanSize>>|
        ifft fftSize'        [9,10,11,15,14] |>>chanSize>>|
        accumulate                   `on` 13 |>>chanSize>>|
        window                       `on` 12 )
    (do buffer <- newArr fftSize
        hasMore :: Data Bool <- liftHost $ callFun "receive_samples" [ arrArg buffer ]
        input :: RealSamples <- unsafeFreezeVec fftSize buffer
        return (input, hasMore))
    chanSize
    (\output -> do
        let Store (_, buffer) = output :: Store RealSamples
        needsMore :: Data Bool <- liftHost $ callFun "emit_samples" [ arrArg buffer ]
        return needsMore)
    chanSize
  onHost $ liftHost $ callProc "teardown_queues" []


main = do
    let outFile = "gen/processor.c"
    h <- openFile outFile WriteMode
    hPutStrLn h $ compile mainProgram
    hClose h
    putStrLn $ "PThread source generated: " P.++ show outFile

    let modules = compileAll `onParallella` mainProgram
    outFiles <- forM modules $ \(name, contents) -> do
        let name' = if name P.== "main" then "host" else name
            path  = "gen/" P.++ name' P.++ ".c"
        writeFile path contents
        return path
    putStrLn $ "Epiphany sources generated: " P.++ show outFiles
