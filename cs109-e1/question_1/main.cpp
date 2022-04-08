/**
 * This is just a test file for question 1
 */

#include <iostream>

using namespace std;

typedef struct a {
	int x, y, z;
};

bool foo(int x);

int main() {
	bool x = true;
	struct a test = {1,2,3};
	cout << "Value of a: " << test.x << test.y << test.z << endl;
	cout << foo(5) << endl;
}

//int foo(int x) {return x;}

//double foo(int x) {return x;}

bool foo(int x) {return 0;}

