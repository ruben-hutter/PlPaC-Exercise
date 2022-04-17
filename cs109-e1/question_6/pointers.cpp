#include <iostream>

using namespace std;

double square (double gaga) {
	return gaga * gaga;
}

// as the input should be increased by  0.3 we need double or flot as return type
double incr (double inp) {
	return inp + 0.3;
}

// as we want to modify the result in place we need it's address and not it's value
void reduce(double value, double* result) {
	*result = value - 3.1;
}

int main () {
	double a = 5, b = 6;
	int values[] = {3, 4, 7, 5, 9};
	// pointer to the first element of values (used later)
	int *pValues = values;

	// as a and b are double varibles and not pointer variables there is nothing to deref in "*(*a) + *b"
	cout << "a + b = " << a + b << endl;

	double *c = &b;
	*c = 2;

	cout << "checking b = 2 now: b = " << *c << endl;
	// as the function square expects a double as argument and c is a double pointer variable we have to deref c first
	cout << "greeting c^2 = " << square(*c) << endl;
	cout << "increase a: " << incr(a) << endl;
	// as we want the value of a and not it's address we dont need the "&" here.
	// further a is a double so this array access makes no sense. I'll just cast it here for this exercise.
	cout << "get a-th element of values: " << *(values + (int)a - 1) << endl;

	// double *z = 0 creates a double pointer pointing to addr 0
	// *z = b + 1 then tries to write to that addr wich causes a segmentation fault error
	double z = 0;
	double *pz = &z;
	*pz = b + 1;
	//cout << "z is now bigger than b: " << *z << endl;
	// values[0] already returns the value. no deref needed
	// ++ can only be used on lvalues
	// to remein in the scheme of using pointers to access array elements we use p-- to acces the first element at the end
	cout << "the 1st element of values is " << values[0] << " and the second is " << *(++pValues) << " and the first again " << *(--pValues) << endl;

	{
		double c = 0;
		// as reduce needs the address of c we get it using &
		reduce(a, &c);
		cout << "a reduced is equal " << c << endl;
	}
}
