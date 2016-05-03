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
  emit $ zipWith (*) input (hann $ length input)

interleave :: Zun (Vector (Data Float)) (Vector (Data (Complex Float))) ()
interleave = loop $ do
  input <- receive
  emit $ map (flip complex 0) input

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

zeroNegFreqs :: Zun (Vector (Data (Complex Float))) (Vector (Data (Complex Float))) ()
zeroNegFreqs = do
  input <- receive
  let l = length input
      l2 = l `div` 2
  emit $ Indexed l $ \i -> (i < l2) ? (input ! i) $ 0

accumulate :: Zun (Vector (Data (Complex Float))) (Vector (Data Float)) ()
accumulate = loop $ do
  input <- receive
  emit $ map ((/ i2n (fftSize * overlap)) . realPart) input

--------------------------------------------------------------------------------
-- Main program and constants
--------------------------------------------------------------------------------

-- Needed to be in sync with C and JS code!
bufferSize :: Data Length
bufferSize = 1024

fftSize :: Data Length
fftSize = 1024

overlap :: Data Length
overlap = 4

sampleRate :: Data Float
sampleRate = 44100

-- Value 1 means no shifting. 2 is one octave up, 0.5 is one octave down.
pitchShift :: Data Float
pitchShift = 2


mainProgram :: Run ()
mainProgram = do
  addInclude "\"processor.h\""
  callProc "setup_queues" []
  let chanSize = 10 `ofLength` bufferSize
  translatePar (liftP (window >>> interleave >>> (fft 1024) >>>
                       cWrapper >>>
                       {-zeroNegFreqs >>> -} (ifft 1024) >>> accumulate >>> window))
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
