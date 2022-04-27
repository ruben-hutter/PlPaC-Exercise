#ifndef ELEMENT_TYPE_H
#define ELEMENT_TYPE_H
#include <string>

using namespace std;

class ElementType {
public:
    string descriptor;
    int uid;
    double* properties;
    list<string> description;
};

#endif