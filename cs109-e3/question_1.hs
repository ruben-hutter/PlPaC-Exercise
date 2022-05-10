-- a) find ith element of a list
atIndex n myList = last (take (n+1) myList)

-- b) generate a list of tuples (n,s)
tupleList = [(x,y) | x <- [3,6..3*25], y <- [sum [1..x]]]

-- c) remove all instances from a list
removeItem i myList = [x | x <- myList, x /= i]

-- d) list containing divisors of integer
getDivisors n = [x | x <- [1..], mod n x == 0]

-- e) list containing shared prime factors of 2 integers
getPrimes n m = [x | x <- [1..(max n m)], x ]