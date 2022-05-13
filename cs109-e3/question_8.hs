import Data.Complex

-- check if c is in mandelbrot set
calc_mandelbrot :: Complex -> Complex -> Int
calc_mandelbrot z c = iter_mandelbrot z c 0

-- check when c leaves mandelbrot set by iteration
iter_mandelbrot :: Complex -> Complex -> Int -> Int
iter_mandelbrot z c iter
    | abs z > 10^3 = iter
    | iter < 100 = calc_mandelbrot z_next c (iter+1)
    | otherwise = 0
    where
        z_next = (z**2) + c

-- get color code from num of iterations
get_color_code :: Int -> Int
get_color_code iter
    | iter == 0 = 37
    | idx < 0 = 34
    | idx > 8 = 31
    | otherwise = colors !! idx
    where
        colors = [34, 35, 31, 32, 36, 34, 35, 31]
        idx = iter - 4

-- wrap string in color
wrap_in_color :: [Char] -> [Char]
wrap_in_color string color = "\x1b[" ++ color ++ "m" ++ s ++ "\x1b[0m"