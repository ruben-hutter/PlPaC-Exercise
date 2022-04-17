#include <iostream>

using namespace std;

int* altAntiParallel(int* a, int alen, int* b, int blen, int* deflt=NULL) {
    int* res;
    if (deflt == NULL) {
        int* res[alen + blen];
    } else {
        int reslen = max(alen, blen) * 2;
        int* res[reslen];
    }
    return res;
}

int main() {
}