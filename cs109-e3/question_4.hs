sorted :: Ord a => [a] -> Bool
sorted a = sortedDesc a || sortedAsc a

sortedDesc :: Ord a => [a] -> Bool
sortedDesc [] = True
sortedDesc [x] = True
sortedDesc (x:y:xs) = (x >= y) && sorted (y:xs)

sortedAsc :: (Ord a) => [a] -> Bool
sortedAsc [] = True
sortedAsc [x] = True
sortedAsc (x:y:xs) = (x <= y) && sorted (y:xs)

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