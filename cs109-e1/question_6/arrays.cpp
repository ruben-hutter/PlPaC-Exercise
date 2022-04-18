#include <algorithm> 
#include <iostream>

using namespace std;

// returns new array containing the elements of the input arrays as stated in the exercise
int* altAntiParallel(int* a, int alen, int*b, int blen, int* deflt = NULL) {
	// position in the result array to populate next
	int r_ptr = 0;
	// length of the result array
	int r_len;
	if (*deflt == NULL) {
		r_len = alen + blen;
	} else {
		r_len = 2 * max(alen, blen);
	}

	// result array
	int* result = (int*) malloc(r_len * sizeof(int));

	// positions in arrays a abd b to take values from
	int a_ptr = 0;
	int b_ptr = blen - 1;

	while(r_ptr < r_len) {
		// if existing, take elem from a
		if (a_ptr < alen) {
			result[r_ptr] = a[a_ptr];
			a_ptr++;
			r_ptr++;
		} else if (*deflt != NULL) {
			// else add blank
			result[r_ptr] = *deflt;
			r_ptr++;
		}

		// if existing, take elem from b
		if (b_ptr > -1) {
			result[r_ptr] = b[b_ptr];
			b_ptr--;
			r_ptr++;
		} else if (*deflt != NULL) {
			result[r_ptr] = *deflt;
			r_ptr++;
		}
	}
	return result;
}

int main() {
	// init arrays and lengths
	int a[] = {1, 2, 3};
	int alen = 3;
	int b[] = {4, 5, 6, 7, 8};
	int blen = 5;

	// set default char
	int deflt = 'D';

	// get result
	int* result = altAntiParallel(a, alen, b, blen, &deflt);

	cout << "Result: [";
	for (int i = 0; i < 10; i++) {
        	cout << result[i] << ",";
    	}
	cout << "].";

	free(result);
	return 0;
}
