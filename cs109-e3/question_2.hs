-- a) infinite list of odd numbers
odds = [1,3..]

-- b) take odds and create tuples
recTuples = zip odds (map (1/) odds)

-- c) take list of tuples and a double
sumTuples tupleLst d = helper tupleLst d 0 0

helper tupleList d idx mySum
    | mySum >= d = []
    | otherwise = tupleList !! idx : helper tupleList d (idx + 1) (mySum + snd (tupleList !! idx))