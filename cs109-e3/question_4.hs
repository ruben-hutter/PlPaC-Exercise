sorted :: (Ord a) => [a] -> Bool
sorted = sorted_desc a || sorted_asc a

sorted_desc :: (Ord a) => [a] -> Bool
sorted_desc [] = True
sorted_desc [x] = True
sorted_desc (x:y:xs) = (x >= y) && sorted (y:xs)

sorted_asc :: (Ord a) => [a] -> Bool
sorted_asc [] = True
sorted_asc [x] = True
sorted_asc (x:y:xs) = (x <= y) && sorted (y:xs)

mergesort :: Ord a => [a] -> [a]
mergesort [] = []
mergesort [a] = [a]
mergesort xs = merge (mergesort (first xs)) (mergesort (second xs))

first  xs = let { n = length xs } in take (div n 2) xs
second xs = let { n = length xs } in drop (div n 2) xs

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys) | x <= y    = x:merge xs (y:ys)
                    | otherwise = y:merge (x:xs) ys