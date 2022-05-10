-- a) find ith element of a list
atIndex n myList = last (take (n+1) myList)

-- b) generate a list of tuples (n,s)
tupleList = [(x,y) | x <- [3,6..3*25], y <- [sum [1..x]]]

-- c) remove all instances from a list
removeItem i myList = [x | x <- myList, x /= i]

-- d) list containing divisors of integer
getDivisors n = [x | x <- [1..n], mod n x == 0]

-- e) list containing shared prime factors of 2 integers
isPrime k = (k > 1) && null [ x | x <- [2..k - 1], k `mod` x == 0]
getPrimes n m = [x | x <- getDivisors n, x `elem` getDivisors m, isPrime x]

-- f) xor two strings
xorStrings s1 s2 = 0

-- g) average of list
average myList = sum myList / fromIntegral (length myList)