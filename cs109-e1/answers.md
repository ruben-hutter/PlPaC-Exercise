# Answers to the questions

## Question 1: Compilation Exercises
1. Will not compile. Return statement is missing.
2. boolean is not the correct way to declare (also initialize) a boolean variable. The correct way would be `bool x = true;`
3. Works fine, the x value will be automatically casted into a double.
4. The struct is ok, the problem is that in the same time it is a typedef, but the name of the new type is missing at the end of the statement. The code will compile but you get a warning that the typedef was ignored.
5. Ok, 0 in return statement is evaluated just fine. 0 is equal to false. 0 will be returned.

## Question 2: Error Search
###b)
Using the g++ compiler, you can compile the programm with: `g++ main.cpp -o pyramid_prog`.