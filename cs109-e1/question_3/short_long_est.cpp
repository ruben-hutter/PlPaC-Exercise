#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void short_long_est() {
    // initialize variable and stringstream object
    stringstream ss;
    string sentence;

    // read input and put it into stringstream
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    // change non-letters to spaces
    for (auto &c : sentence) {
        if (!isalpha(c)) {
            c = ' ';
        }
    }
    ss << sentence;

    // initialize string variables
    string shortest_word;
    string longest_word;
    string current_word;

    // set shortest_word and longest_word to
    // the first word of the sentence
    ss >> current_word;
    shortest_word = current_word;
    longest_word = current_word;

    // iterate throught the ss until end-of-file flag is set,
    // and update shortest and longest word
    while (ss.peek() != EOF) {
        ss >> current_word;
        if (current_word.length() < shortest_word.length()) {
            shortest_word = current_word;
        } else if (current_word.length() > longest_word.length()) {
            longest_word = current_word;
        }
    }

    // output result
    cout << "Longest = " << longest_word << ", Shortest = " << shortest_word << endl;
}

int main() {
    short_long_est();
    return 0;
}