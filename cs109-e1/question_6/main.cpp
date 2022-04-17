#include <iostream>

using namespace std;

double square(double gaga) {
	return gaga * gaga;
}

int incr(double inp) {
	int res = inp + 0.3;
	return res;
}

void reduce(double value, double result) {
	result = value - 3.1;
}

int main() {
	double a = 5, b = 6;
	int values[] = {3, 4, 7, 5, 9};

	cout << "a + b = " << *(*a) + *b << endl;

	double *c = &b;
	*c = 2;

	cout << "checking b = 2 now : b = " << *c << endl;
	cout << "geeting c^2 = " << square(c) << endl;
	cout << "increase a: " << incr(a) << endl;
	cout << "get a-th element of values: " << *(values + &a - 1) << endl;

	double *z = 0;
	*z = b + 1;
	cout << "z is now bigger than b: " << *z << endl;
	cout << "the 1st element of values is " << *values[0]
		<< " and the second is " << ++values << " and the first again "
		<< values[-1] << endl;
	{
		double c = 0;
		reduce(a, c);
		cout << "a reduced is equal " << c << endl;
	}
}

