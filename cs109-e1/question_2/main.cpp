#include "pyramid.h"
#include <iostream> //was missing: cout can't be used withoud

using namespace std;

int main() {
	int base, height;

	cout << "Enter the base side of the a sqare-based pyramid: ";
	cin >> base; //cin << something is not correct. the input must go into the variable, not viceversa...

	cout << "Enter the height of the pyramid: ";
	cin >> height;

	PYRAMID* pyramid = construct_pyramid(base, height);
	PYRAMID& pyramid_ref = *pyramid;

	cout << "The volume of the pyramid is: " << *calculate(pyramid_ref) << endl; //dereference return value of calculate()

	return 0;
}
