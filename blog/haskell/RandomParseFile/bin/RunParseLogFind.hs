--
-- RunParseLogFind.hs
-- Haskell version of open and parse log file script
-- version 7.0.3

import System.IO
import Text.Regex (splitRegex, mkRegex, matchRegex, matchRegexAll)

patternToMatch = "(called)" 

-- Data Type, Main File Loop Info 
data LoopInf = DataInf [String]

-- Find the last values in the list
c :: [String] -> [String]
c l = take 4 l

-- Loop through input file
loadFileLoop :: Handle -> Handle -> [String] -> IO ([String])
loadFileLoop inh outh lst =
    do inEof <- hIsEOF inh
       if inEof
            then return (lst) 
            else do line <- hGetLine inh
                    do case matchRegex (mkRegex patternToMatch) line of
                            Just (fn:_) -> hPutStrLn outh line 
                            _ -> return ()
                    loadFileLoop inh outh (c (line:lst))

-- Main Entry Point
main :: IO ()
main = do
    putStrLn "Running"
    inh  <- openFile "logs/my.log" ReadMode
    outh <- openFile "logs/Results.dat" WriteMode
    res  <- loadFileLoop inh outh []
    hClose inh
    hClose outh
    putStrLn (show res)
    putStrLn "Done"

-- End of File --
-- End of File //
