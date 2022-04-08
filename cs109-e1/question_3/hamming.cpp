#include <string>
#include <iostream>

using namespace std;

/**
 * Function which calculates the Hamming distance
 * between twostrings of equal length.
 */
void hamming() {
    string str_1, str_2;

    cout << "Enter first string to compare: ";
    getline(cin, str_1);
    cout << "Enter second string to compare: ";
    getline(cin, str_2);

    if (str_1.length() != str_2.length()) {
        cout << "String have not same length!" << endl;
        return;
    }

    int distance = 0;

    for (int i = 0; i < str_1.length(); i++) {
        char char_1 = tolower(str_1[i]);
        char char_2 = tolower(str_2[i]);
        if (char_1 != char_2) {
            distance++;
        }
    }

    cout << "The Hamming distance between " << str_1 << " and "
            << str_2 << " is " << distance << endl;
}

int main() {
    hamming();
    return 0;
}