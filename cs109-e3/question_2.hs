-- a) infinite list of odd numbers
odds = [1,3..]

-- b) take odds and create tuples
recTuples = zip odds (map (1/) odds)

-- c) take list of tuples and a double
checkSum = 0
sumTuples tupleLst d = takeWhile (/= (1,1)) tupleLst