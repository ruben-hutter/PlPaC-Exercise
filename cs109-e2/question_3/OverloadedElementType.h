#ifndef OVERLOADED_ELEMENT_TYPE_H
#define OVERLOADED_ELEMENT_TYPE_H

#include "ElementType.h"
#include <list>
#include <algorithm>

using namespace std;

class OverloadedElementType: public ElementType {
    double& operator[](int param_number);
    OverloadedElementType operator-(const OverloadedElementType& that);
};

#endif