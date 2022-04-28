#ifndef BASE_CHANGE_ELEMENT_TYPE_H
#define BASE_CHANGE_ELEMENT_TYPE_H

#include "OverloadedElementType.h"


using namespace std;

class BaseChangeElementType: public OverloadedElementType {
public:
    // ctor
    BaseChangeElementType(string descriptor, int uid, double* props, list<string> description);

    struct convertA2B {
        // ctor
        convertA2B(){}
        BaseChangeElementType operator()(const BaseChangeElementType& elem) const;
    private:
        const float ERG_JOULE_MULT = 0.0000001;
        const float FEET_METER_MULT = 0.3048;
        const int F_C_SUBTRACT = -32;
        const float F_C_MULT = 5/9.0f;
        const float PS_KW_MULT = 0.7385499;
    };
    struct convertB2A {
        // ctor
        convertB2A(){}  // Constructor
        BaseChangeElementType operator()(const BaseChangeElementType& elem) const;
    private:
        const float JOULE_ERG_MULT = 1/0.0000001;
        const float METER_FEET_MULT = 1/0.3048;
        const int C_F_ADD = 32;
        const float F_C_MULT = 9/5.0f;
        const float PS_KW_MULT = 1/0.7385499; 
    };
};

#endif
