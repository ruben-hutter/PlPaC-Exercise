#include <iostream>
#include <math.h>

/**
* Compare according to the cosine value
* of the 2nd element of the array.
* @return -1, 0, 1
*/
int compare_cos(double* array1, double* array2) {
    int ret = 0;
    double res1 = cos(array1[1]);
    double res2 = cos(array2[1]);
    if (res1 < res2) {
        ret = -1;
    } else if (res2 < res1) {
        ret = 1;
    }
    return ret;
}

/**
* Consider array a point in the Euclidian space R3
* and compare L1-Norm distance.
* @return -1, 0, 1
*/
int compare_taxicab(double* array1, double* array2) {
    int ret = 0;
    double res1 = abs(array1[0]) + abs(array1[1]) + abs(array1[2]);
    double res2 = abs(array2[0]) + abs(array2[1]) + abs(array2[2]);
    if (res1 < res2) {
        ret = -1;
    } else if (res2 < res1) {
        ret = 1;
    }
    return ret;
}

/**
* Check if the first or the second array is bigger,
* according to the comparator function.
* @return -1, 0, 1
*/
int compare(double* array1, double* array2, int func(double*, double*)) {
    return func(array1, array2);
}

int main() {
    double *array1 = new double[3] {75, 5, 29};
    double *array2 = new double[3] {1, 10, 7};
    std::cout << compare(array1, array2, compare_cos) << std::endl;
    std::cout << compare(array1, array2, compare_taxicab) << std::endl;
}