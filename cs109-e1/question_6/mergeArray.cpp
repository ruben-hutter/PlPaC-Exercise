#include <iostream>

using namespace std;

int* altAntiParallel(int* a, int alen, int* b, int blen, int* deflt=NULL) {
    int* res;
    int reslen;
    int pos = 0;
    // check which array is larger
    if (alen < blen) {
        // b is larger

        // check if deflt is given
        if (deflt == NULL) {
            // alternate until POS < alen, than fill with remaining b
            reslen = alen + blen;
            res[reslen];

            // alternate until POS < alen
            for (int i = 0; i <= 2*alen; i++) {
                res[i] = (i % 2 == 0) ? a[pos] : b[blen-1-pos++];
            }
            // fill with remaining b
            int bpos = alen-1;
            for (int i = alen+1; i < blen; i++) {
                res[i] = b[bpos--];
            }
        } else {
            // alternate until POS < alen, than alternate deflt and b
            reslen = 2 * blen;
        }
    } else {
        // a larger or equal b

        // check if default is given
        if (deflt == NULL) {
            // alternate until POS < blen, than fill with remaining a
        } else {
            // alternate until POS < blen, than alternate deflt and a
        }
    }
    return res;
}

int main() {
    int a[] = {1, 2};
    int b[] = {4, 5, 6};
    int* res = altAntiParallel(a, 2, b, 3);
    for (int i = 0; i < 5; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
