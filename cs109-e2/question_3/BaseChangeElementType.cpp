#include "BaseChangeElementType.h"

BaseChangeElementType::BaseChangeElementType(string descriptor, int uid, double* props, list<string> description)
:OverloadedElementType(descriptor, uid, props, description) {
    // emtpy body
};

BaseChangeElementType BaseChangeElementType::convertA2B::operator()(const BaseChangeElementType& elem) const {

};

BaseChangeElementType BaseChangeElementType::convertB2A::operator()(const BaseChangeElementType& elem) const {

};
