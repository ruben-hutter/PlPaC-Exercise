#include "pyramid.h"
//#include <math.h>		not needed

PYRAMID construct_pyramid(int base, int height) { //the name of the function has to be the same as in the header file.
	PYRAMID p = {base, height};
	return p;
}

double calculate(PYRAMID &p) {
	double res = (double)1/3 * (p.base * p.base) * p.height; //at least a parameter must be double in the division, or an int division will be executed.
	return res; //you want to return the result, not the adress of result
}
