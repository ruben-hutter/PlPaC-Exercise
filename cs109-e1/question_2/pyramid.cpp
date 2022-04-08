#include "pyramid.h"
#include <math.h>

PYRAMID* construct(int base, int height) { //the return value has to be also a pointer to a PYRAMID object
	PYRAMID p = {base, height}; 
	PYRAMID *p_ptr = &p; //p must be a pointer because it is initialized in a method and then returned.
	return p_ptr;
}

double* calculate(PYRAMID &p) {
	double res = 1/3 * (p.base * p.base) * p.height;
	double *res_ptr = &res; //same as with construct(). pointer has to be returned
	return res_ptr;
}
