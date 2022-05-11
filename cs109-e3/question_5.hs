map :: (a -> b) -> [a] -> [b]
map _ []     = []
map f (x:xs) = f x : map f xs

filter :: (a -> Bool) -> [a] -> [a]
filter p (x:xs)
    | p x = x : filter p xs
    | otherwise = filter p xs
filter _ [] = []

lenAndSum :: [a] -> (Int,Int)
lenAndSum xs = go (0,0) xs
  where go (s1,s2) [] = (s1,s2)
        go (s1,s2) (a:as) = go (s1+1, s2+=a) as

mean xs = let (a, b) = lengthAndSum xs in (fromIntegral b / fromIntegral a)

pearson:: [Int], [Int] -> Double
pearson x y
-- create two sets with xi-xavg
dx = mean_diff x
dy = mean_diff y
-- mult and sum
upper = sum (zipWith (*) dx dy)
-- square with maps
dx2 = map (^2) dx
dy2 = map (^2) dy
lower = 


mean_diff x = map (subtract mean x) x

audienceScore = [91, 70, 71, 76, 75, 91, 78, 75, 92, 92, 83, 85, 89, 86,
87, 87, 87, 79, 91, 81, 45, 90, 95, 91, 98, 78, 98]

movieDuration = [126, 112, 124, 113, 124, 143, 130, 111, 135, 121, 141,
117, 146, 115, 135, 133, 130, 134, 149, 118, 124, 181, 129, 133, 133, 157,
148]

boxOffice = [186, 137.5, 170, 150, 140, 225, 200, 150, 170, 170, 365, 130,
250, 165, 200, 175, 180, 200, 300, 130, 175, 400, 160, 200, 150, 200, 200]