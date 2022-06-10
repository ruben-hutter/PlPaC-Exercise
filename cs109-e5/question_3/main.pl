ackermann(M, N, 0, MN) :- MN is M+N.
ackermann(_, 0, 1, 0).
ackermann(_, 0, 2, 1).
ackermann(M, 0, P, M) :- P>2.
ackermann(M, N, P, X1) :- N>0, P>0, N2 is N-1,ackermann(M, N2, P, X2), P2 is P-1, ackermann(M, X2, P2, X1).

palindromGenerator(X, Xpal) :- revList(X, Xrev), append(X, Xrev, Xpal).

revList([], []).
revList([X|Xs], Xrev) :- revList(Xs, Xsrev), append(Xsrev, [X], Xrev).
