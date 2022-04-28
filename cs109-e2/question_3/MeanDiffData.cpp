#include "MeanDiffData.h"

void MeanDiffData::mean_diff() {
    string descriptor = "mean element";
    list<string> description;
    description.push_front("mean of properties of other elements");
    int uid = 0;
    double property_means[10];
    // inti array
    for (int i = 0; i < 10; i++) {
        property_means[i] = 0;
    }
    // sum properties
    for (std::list<OverloadedElementType>::iterator it = data_list.begin(); it != data_list.end(); it++){
        for (int i = 0; i < 10; i++) {
            property_means[i] = it->properties[i];
        }
    }
    // calc mean for each property
    for (int i = 0; i < 10; i++) {
        property_means[i] /= data_list.size();
    }
    // set mean elem
    mean_elem = OverloadedElementType(descriptor, uid, property_means, description);
    // convert rest of elements
    for (OverloadedElementType& elem : data_list){
        data_list.push_back(mean_elem-elem);
        data_list.remove(elem);
    }
}

OverloadedElementType MeanDiffData::getMeanElem() {
    return mean_elem;
}
