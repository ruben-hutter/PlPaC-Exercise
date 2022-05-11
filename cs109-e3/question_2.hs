-- a) infinite list of odd numbers
odds = [1,3..]

-- b) take odds and create tuples
recTuples = zip odds (map (1/) odds)