#ifndef OVERLOADED_ELEMENT_TYPE_H
#define OVERLOADED_ELEMENT_TYPE_H

#include "ElementType.h"
#include <algorithm>

using namespace std;

class OverloadedElementType: public ElementType {
public:
    OverloadedElementType(string descriptor, int uid, double* props, list<string> description);
    double& operator[](int param_number);
    OverloadedElementType operator-(OverloadedElementType& that);
};

#endif