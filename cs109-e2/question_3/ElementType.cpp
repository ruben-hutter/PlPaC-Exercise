#include "ElementType.h"

ElementType::ElementType(string descriptor, int uid, double* props, std::list<string>* description) {
    this->descriptor = descriptor;
    this->description = *description;
    this->uid = uid;
    this->properties = props;
    this->description = *description;
}