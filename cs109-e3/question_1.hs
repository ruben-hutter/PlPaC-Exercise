-- a) find ith element of a list
myList = [1, 2, 3, 4]
atIndex = myList !! 2

-- b) generate a list of tuples (n,s)
tupleList = [ (x,y) | x <- [3,6..3*25], y <- [sum [1..x]]]

-- c) remove all instances from a list
