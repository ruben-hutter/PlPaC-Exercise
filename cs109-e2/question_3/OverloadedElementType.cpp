#include "OverloadedElementType.h"

double& OverloadedElementType::operator[](int param_number) {
    if (param_number >= 10) {
        return;
    }
    return this->properties[param_number];
}

OverloadedElementType OverloadedElementType::operator-(const OverloadedElementType& that) {
    for (int i = 0; i < 10; i++) {
        this->properties[i] -= that.properties[i];
        // get intersection of two lists
        std::list<OverloadedElementType> intersection;
        std::set_intersection(this->description.begin(), this->description.end(),
            that.description.begin(), that.description.end(),
            std::back_inserter(intersection));
        // get union of lists: doesn't work because of const -> WTF how should this be solved?
        this->description.merge(that.description);
        // remove intersection from union
        std::list<OverloadedElementType> difference;
        std::set_difference(this->description.begin(), this->description.end(),
            that.description.begin(), that.description.end(),
            std::back_inserter(difference));
        this->description = difference;
    }
}