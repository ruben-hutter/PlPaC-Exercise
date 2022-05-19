mmap :: (a -> b) -> [a] -> [b]
mmap _ []     = []
mmap f (x:xs) = f x : mmap f xs

mfilter :: (a -> Bool) -> [a] -> [a]
mfilter p (x:xs)
    | p x = x : mfilter p xs
    | otherwise = mfilter p xs
mfilter _ [] = []

lenAndSum :: Real a => [a] -> (a,a)
lenAndSum xs = go (0,0) xs
    where
        go (s1,s2) [] = (s1,s2)
        go (s1,s2) (a:as) = go (s1+1, s2+a) as

mean :: (Real m, Fractional n) => [m] -> n
mean xs = let (a, b) = lenAndSum xs in (realToFrac b / realToFrac a)

meanDiff :: (Real mi, Fractional n, Fractional mi) => [mi] -> [n]
meanDiff x = map realToFrac y
    where
        x_ = mean x
        y = map (subtract x_) x

pearson :: (Real m, Fractional n, Fractional m, Floating n) => [m] -> [m] -> n
pearson x y = upper / lower
    where
        dx = meanDiff x
        dy = meanDiff y
        upper = sum (zipWith (*) dx dy)
        dx2 = sum (map (^2) dx)
        dy2 = sum (map (^2) dy)
        lower = sqrt dx2 * sqrt dy2

audienceScore :: Fractional a => [a]
audienceScore = [91, 70, 71, 76, 75, 91, 78, 75, 92, 92, 83, 85, 89, 86,
  87, 87, 87, 79, 91, 81, 45, 90, 95, 91, 98, 78, 98]

movieDuration :: Fractional a => [a]
movieDuration = [126, 112, 124, 113, 124, 143, 130, 111, 135, 121, 141,
  117, 146, 115, 135, 133, 130, 134, 149, 118, 124, 181, 129, 133, 133, 157,
  148]

boxOffice :: Fractional a => [a]
boxOffice = [186, 137.5, 170, 150, 140, 225, 200, 150, 170, 170, 365, 130,
  250, 165, 200, 175, 180, 200, 300, 130, 175, 400, 160, 200, 150, 200, 200]