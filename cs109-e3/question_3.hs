ackFun m n p
    | p == 0 = m + n
    | n == 0 && p == 1 = 0
    | n == 0 && p == 2 = 1
    | p > 2 = m
    | otherwise = ackFun m (ackFun m (n-1) p) (p-1)

ackermannList s
    | s == []
    | s == [x] = ackFun x 0 3
    | s == [x, y] = ackFun x y 0
    | s == [x, y, z] = ackFun x y z
    | otherwise = ackFun m (ackFun m (n-1) p) (p-1)