-- uncurried version
-- if first value is True foo returns the sum of the other two args
-- if the first value is false, foo returns the difference of the two other args
foo :: (Bool, Int, Int) -> Int
foo (x, y, z)
    | x = y + z
    | otherwise = y - z

-- curried version
curryFoo :: Bool -> Int -> Int -> Int
curryFoo x y z 
    | x = y + z
    | otherwise = y - z