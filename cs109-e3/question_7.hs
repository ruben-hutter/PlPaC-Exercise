import Data.Char
import Data.Bits

main = putStrLn(getAsciiChars(decode_recursive x y z))
    where
        x = [18, 68, 36, 36, 20, 67, 36, 20, 36, 35, 68, 20, 20, 36, 68, 33, 65, 20, 20, 35, 36, 17, 36,
            65, 36, 17, 68, 20, 68, 33, 33, 19, 20, 35, 67, 33, 35, 18, 68, 20, 68, 36, 68, 19, 36, 65, 68,
            36, 20, 68, 35, 20, 20, 35, 17, 36, 68, 17, 68, 36, 33]

        y = [19, 34, 66, 32, 34, 20, 67, 19, 65, 36, 35, 33, 34, 66, 19, 19, 17, 18, 34, 22, 35, 65, 34,
            36, 19, 65, 18, 34, 64, 65, 17, 68, 19, 33, 68, 33, 64, 64, 18, 36, 67, 33, 18, 71, 16, 65, 32,
            36, 16, 66, 36, 17, 35, 37, 65, 19, 66, 17, 64, 34, 33]

        z = [34, 65, 32, 67, 20, 66, 33, 66, 35, 18, 65, 16, 17, 32, 64, 36, 66, 33, 16, 35, 70, 18, 32,
            35, 17, 66, 65, 16, 33, 34, 18, 67, 18, 36, 64, 34, 66, 66, 16, 33, 70, 20, 65, 20, 33, 34, 65,
            64, 65, 20, 20, 32, 16, 65, 18, 33, 33, 66, 35, 17, 19]

decode_recursive :: [Int] -> [Int] -> [Int] -> [Int]
decode_recursive [] [] [] = []
decode_recursive x y z
    | uc == -1 = [] ++ decode_recursive (tail x) (tail y) (tail z)
    | otherwise = return (uc) ++ decode_recursive (tail x) (tail y) (tail z)
    where
        uc = uncover (head x) (head y) (head z)

getAsciiChars :: [Int] -> [Char]
getAsciiChars ints = map(chr) ints

uncover :: Int -> Int -> Int -> Int
uncover x y z
    | shiftR y 4 == shiftR z 4 = -1
    | otherwise = tx*5^2 + ty*5^1+ tz
    where
        n = 15
        tx = x .&. n
        ty = y .&. n
        tz = z .&. n
