ackFun m n p
    | p == 0 = m + n
    | n == 0 && p == 1 = 0
    | n == 0 && p == 2 = 1
    | p > 2 = m
    | otherwise = ackFun m (ackFun m (n-1) p) (p-1)

ackermannList:: [Int] -> [Int]
ackermannList [] = [13]
ackermannList [x] = [ackFun x 0 3]
ackermannList [x, y] = [ackFun x y 0]
ackermannList [x, y, z] = [ackFun x y z]
ackermannList (x:y:z:rest) = ackFun x y z : ackermannList rest