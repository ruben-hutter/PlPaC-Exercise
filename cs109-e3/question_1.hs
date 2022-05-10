-- a) find ith element of a list
atIndex :: Int -> [a] -> a
atIndex n myList | n == 0    = head myList
                 | otherwise = last (take (n+1) myList)

-- b) generate a list of tuples (n,s)
tupleList = [ (x,y) | x <- [3,6..3*25], y <- [sum [1..x]]]

-- c) remove all instances from a list

