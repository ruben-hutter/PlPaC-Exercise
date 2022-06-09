% a)
lst([3, 5, 7, 9]).

listLength([], Len) :- Len is 0.
listLength([_|Xs], Len) :- listLength(Xs, Len1), Len is Len1+1. 

rev([],[]).
rev([X|Xs], Xrev) :- rev(Xs, Xsrev), append(Xsrev, [X], Xrev).

pop([], _, []).
pop([X|Xs], X, Xs).

% b)
isFactor(X, Y) :- 0 is mod(X, Y).

getPrimeFactor(1, _, 1). % define prime factor of 1 to be 1
getPrimeFactor(X, Y, F) :- X =:= Y, F is Y, !. % if X is divisible by itself, then X is the largest prime factor
getPrimeFactor(X, Y, F) :- X > Y, isFactor(X, Y), getPrimeFactor(X/Y, Y, F2), F is max(Y, F2), !.
getPrimeFactor(X, Y, F) :- X > Y, not(isFactor(X, Y)), getPrimeFactor(X, Y+1, F).

largestPrimeFactor(X, Y) :- getPrimeFactor(X, 2, Y).

isPrime(X) :- X > 1, largestPrimeFactor(X, X).