#include <cstdio>
#include <math.h>

// struct for representing complex numbers
typedef struct Complex {
	double real;
	double imag;
} Complex;

// function for adding complex numbers
Complex add(Complex first, Complex second){
	return Complex{first.real + second.real, first.imag + second.imag};
}

// function for subtracting complex nubers
Complex subtract(Complex first, Complex second) {
	return Complex{first.real - second.real, first.imag - second.imag};
}

// function for multiplying complex nubers
Complex mult(Complex first, Complex second) {
	double real_part = (first.real * second.real) - (first.imag * second.imag);
	double imag_part = (first.real * second.imag) + (first.imag * second.real);
	return Complex{real_part, imag_part};
}

// function for dividing two complex numbers
Complex div(Complex first, Complex second) {
	double real_part = (((first.real) * (second.real)) + ((first.imag) * (second.imag))) / (pow(second.real, 2) + pow(second.imag, 2));
	double imag_part = (((second.real) * (first.imag)) - ((first.real) * (second.imag))) / (pow(second.real, 2) + pow(second.imag,2));
	return Complex{real_part, imag_part};
}
// test code
int main() {
	// init complex numbers
	Complex a, b, c, d, result;
	a = {1, 5};
	b = {5, 3};
	c = {2, -3};
	d = {2, -4};
	// run calculation example from exercise
	result = subtract(a, div(add(b, c), d));
	printf("The result is: (%f + %fi)\n", result.real, result.imag);
}
