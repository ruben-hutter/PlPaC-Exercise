#include "OverloadedElementType.h"

OverloadedElementType::OverloadedElementType(string descriptor, int uid, double* props, list<string> description)
:ElementType(descriptor, uid, props, description) {
};

double& OverloadedElementType::operator[](int param_number) {
    if (param_number >= 10) {
        return;
    }
    return this->properties[param_number];
}

OverloadedElementType OverloadedElementType::operator-(OverloadedElementType& that) {
    double new_props[10];
    for (int i = 0; i < 10; i++) {
        new_props[i] = this->properties[i] - that.properties[i];
    }
    // get intersection of two lists
    std::list<OverloadedElementType> intersection;
    std::list<string> new_description;
    std::set_intersection(this->description.begin(), this->description.end(),
        that.description.begin(), that.description.end(),
        std::back_inserter(intersection));
        // get union of lists
        new_description.merge(this->description);
        new_description.merge(that.description);
        // remove intersection from union
        std::list<OverloadedElementType> difference;
        std::set_difference(new_description.begin(), new_description.end(),
            intersection.begin(), intersection.end(),
            std::back_inserter(new_description));
    int new_uid = -this->uid;
    string new_descriptor = this->descriptor + " " + that.descriptor;
    return OverloadedElementType(new_descriptor, new_uid, new_props, new_description);
}