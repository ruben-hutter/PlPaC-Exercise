#include <iostream>

using namespace std;

int main() {
	// a new variable called a containing the value 6 is declared and initialized
	int a = 6;
	// a new variable called b containing hthe value 8 is declared and initialized
	int b = 8;
	// first a new int pointer p pointing to the memory address of a is initialized
	// second a pointer q is initialized wich points to a int pointer pointing to the memory address of a. So we have **q -> *p -> &b.
	int *p = &a, **q = &p;
	/*
	Knowing the binding of the operators we can rewrite as *p *= 3 * (*&b) * (**q).
	(*&b) gets a reference to the variable b using & and dereferences it using * thus
	we get the value of b. As q is a pointer to a pointer pointing to the memory address of a,
	the first * gets us the pointer to the memory address of a. The second * dereferences
	the pointer. We thus get the value of a.
	As p is a pointer to the memory address of a, we can rewrite *p as a.

	The line can thus be rewritten as a *= 3*a*b.
	The value of a gets multiplied by 3*a*b. The result overwrites the value in a.
	*/
	*p *= 3**&b***q;

	// the pointer p now points to the memory address of b
	p = &b;
	// p is dereferenced getting us the value of b. We increment b by one.
	(*p)++;
	// this statement is invalid as we try to assign an int value to an int pointer
	// this synthax could be used if p had been a reference to b.
	p = ++a;
	// same as line above
	p *= 3;
	// As p is a pointer the value op p is a memory address.
	// Our output would contain the memory address of b in position of the p.
	// (p+(p-8) simply returnes the result of this calculation if applied to the memory addresses
	// if the pointer would have been dereferences like *(p+(p-8) the value stored at the
	// resulting address would appear in the string
	cout << a << " " << b << " " <<  p << " " << (p+(p-8)) < endl;
	return 0;
}
