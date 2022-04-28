#ifndef ELEMENT_TYPE_H
#define ELEMENT_TYPE_H
#include <string>
#include <list>

using namespace std;

class ElementType {
public:
    ElementType(string descriptor, int uid, double* props, list<string> description);
    list<string> getDescription();
    string descriptor;
    int uid;
    double* properties;
    list<string> description;
};

#endif