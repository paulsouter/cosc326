-- COSC326
-- Etude 2: Syllables
-- Shaun Kerr, Kurt Weston, James Douglas, Paul Souter
-- The Glorious Glasgow Haskell Compilation System, version 8.0.2

import Data.Char
import System.IO
import Control.Monad

-- Main Loop to grab and process input
main :: IO ()
main = do
   eof <- isEOF
   unless eof $ do
      s <- getLine
      putStrLn $ show $ sum $
         map (\t -> syll $ motherhack $ moUpper t) $ words s
      main

-- Quick helper to convert a string to uppercase
moUpper :: String -> String
moUpper s = map toUpper s

-- Return the last n items of an array
lastn :: Int -> [a] -> [a]
lastn n xs = drop (length xs - n) xs

-- Count the number of vowel sections in a word
syll :: String -> Integer
syll s = sum $ map
   (\c -> if isVowel c then 1 else 0) $ comp s

-- Return if two letters are of the same type (Consonant or Vowel)
isSame :: Char -> Char -> Bool
isSame a b = (isConst a && isConst b) || (isVowel a && isVowel b)

-- Return if a letter is a consonant
isConst :: Char -> Bool
isConst c = (isAlpha c) && (not $ isVowel c)

-- Return if a letter is a vowel
isVowel :: Char -> Bool
isVowel c = c `elem` "AOEUIY"

-- Compress sequences of letters that are of the same type, to a single letter
comp :: String -> String
comp (x:y:zs) = if (isSame x y) then comp (x:zs) else (x: comp (y:zs))
comp zs = zs

-- Apply all hacks
motherhack :: String -> String
motherhack s = tlahack $ ablehack $ scioushack $ yinghack $ aiolihack $ drope 
               $ thmhack $ xdihack s

-- Fix words containing 'YING'
yinghack :: String -> String
yinghack (w:x:y:z:zs) = if (w == 'Y') && (x == 'I')
   && (y == 'N') && (z == 'G')
      then (w:'X':x:y:z: yinghack zs)
      else (w: yinghack (x:y:z:zs))
yinghack a = a

-- Fix words containing 'ABLE'
ablehack :: String -> String
ablehack (v:w:x:y:z:zs) = if (w == 'A') && (x == 'B')
   && (y == 'L') && (z == 'E')
      then (v:'X':w:x:y:z: ablehack zs)
      else (v: ablehack (w:x:y:z:zs))
ablehack a = a

-- Fix words containing any of the sequences defined here
tlahack :: String -> String
tlahack (x:y:z:zs) = if ((x == 'A') && (y == 'I') && (z == 'A')) ||
                        ((x == 'U') && (y == 'I') && (z == 'E')) ||
                        ((x == 'E') && (y == 'E') && (z == 'A')) ||
                        ((x == 'L') && (y == 'I') && (isVowel z)) ||
                        ((x == 'U') && (y == 'O') && (z == 'U')) ||
                        ((x == 'A') && (y == 'Y') && (z == 'A')) ||
                        ((x == 'I') && (y == 'O') && (z == 'U')) ||
                        ((x == 'O') && (y == 'U') && (z == 'A'))
   then (x:y:'X':z: tlahack zs)
   else (x: tlahack (y:z:zs))
tlahack a = a

-- Fix words containing 'CIOUS'
scioushack :: String -> String
scioushack (v:w:x:y:z:zs) = if (v == 'C') && (w == 'I') &&
   (x == 'O') && (y == 'U') && (z == 'S')
      then (v:w:z: scioushack zs)
      else (v: scioushack (w:x:y:z:zs))
scioushack a = a

-- Fix the word 'AIOLI'
aiolihack :: String -> String
aiolihack s | (moUpper $ take 3 s) == "AIO" = (head s:'X':tail s)
aiolihack s = s

-- Fix silent 'E' on the end of words
drope :: String -> String
drope s | (toUpper $ last aaa) == 'E' &&
   not (all isConst $ init aaa) = init s
   where aaa = lastn 3 s
drope s = s

-- Fix words ending with 'THM'
thmhack :: String -> String
thmhack (x:y:z:zs) = if (x == 'T') && ( y == 'H') && ( z == 'M')
   then(x:'A':y:z: thmhack zs)
   else(x: thmhack (y:z:zs))
thmhack s = s

-- Fix words with 'XDI'
xdihack :: String -> String
xdihack (v:w:x:y:z:zs) = if (isVowel v || isConst v ) && (w =='D') && 
   (x=='I') && (isVowel y) && (isConst z) && (z /= 'S')
   then(v:w:x:'X':y:z: xdihack zs)
   else(v: xdihack(w:x:y:z:zs))
xdihack s = s

