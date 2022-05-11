-- a) infinite list of odd numbers
odds = [1,3..]

-- b) take odds and create tuples
recTuples = zip odds (map (1/) odds)

-- c) take list of tuples and a double
sumTuples tupleLst d = sumTupFun tupleLst d 0 0

sumTupFun tupleLst d idx mySum
    | mySum >= d    = []
    | otherwise     = (tupleLst !! idx) ++ sumTupFun tupleLst d (idx + 1) (mySum + snd (tupleLst !! idx))