import Data.Complex

main = mapM_ putStrLn result
    where
        result = [get_line x | x <- x_range]
        x_range = [-1.5, -1.4..1.5]

get_line :: Double -> String
get_line x = concat [get_entry c x | c <- y_range]
    where
        y_range = [-2, -1.95..1]      

get_entry :: Double -> Double -> String
get_entry c ci = wrap_in_color (get_char iter) (get_color_code iter)
    where
        iter = calc_mandelbrot c ci 

-- check if c is in mandelbrot set
calc_mandelbrot :: Double -> Double -> Int
calc_mandelbrot c ci = iter_mandelbrot 0 0 c ci 0

-- check when c leaves mandelbrot set by iteration
iter_mandelbrot :: Double -> Double -> Double -> Double -> Int -> Int
iter_mandelbrot z zi c ci iter
    | abs z zi > 10^3 = iter
    | iter < 100 = iter_mandelbrot z_next zi_next c ci (iter+1)
    | otherwise = 0
    where
        z_next = z**2 - zi**2 + c
        zi_next = (2*z*zi) + ci
        abs z zi = sqrt (z**2 + zi**2)

-- get color code from num of iterations
get_color_code :: Int -> Int
get_color_code iter
    | iter == 0 = 37
    | idx < 0 = 34
    | idx > 7 = 31
    | otherwise = colors !! idx
    where
        colors = [34, 35, 31, 32, 36, 34, 35, 31]
        idx = iter - 4

get_char :: Int -> String
get_char iter
    | iter == 0 = "*"
    | otherwise = "." 

-- wrap string in color
wrap_in_color :: String -> Int -> String
wrap_in_color string color = "\x1b[" ++ show (color) ++ "m" ++ string ++ "\x1b[0m"