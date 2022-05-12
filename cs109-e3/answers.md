# Programming Paradigms - Haskell

## Question 2

**a)**: Haskell loads lists on runtime, so if you only need 5 elements of the list, it will only load the first 5 for you `take 5 myInfList`.


## Question 5
    * mean audienceScore: ...
    * mean boxOffice: ...
    * mean movieDuration: ...

    * set with the highest correlation coefficient: ...

## Question 6
**a)**:
    Currying is a process that transforms a function with multiple arguments into a set of functions where the first function takes the first argument and returns the second function eich takes the 2nd argument and so forth. THe last function then returns the value. This process is required as in Haskell fucntions can only have one argument. Functions with multiple arguments are curried by default.

    Every function with more than one argument can be curried.

**b)**:
    The code defines the lambda expression foo that takes to values and returns their product. This is achieved by taking the first value called x and map to a function taking the second value y wich returns the product of x and y. The method of using two functions that take one argument each is identical to currying.