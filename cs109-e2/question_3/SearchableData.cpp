#include "SearchableData.h"

void SearchableData::sort_ascending_search(int param_number){
    if (param_number == 11) {
        data_list.sort(ascending_comp_sum);
    }
    using namespace std::placeholders;
    std::sort(data_list.begin(), data_list.end(), std::bind(ascending_comp, _1, _2, param_number));
}

void SearchableData::sort_ascending_access(int param_number) {
    if (param_number == 11) {
        
    }

}

void SearchableData::sort_descending_search(int param_number) {
    if (param_number == 11) {
        data_list.sort(descending_comp_sum);
    }
    using namespace std::placeholders;
    std::sort(data_list.begin(), data_list.end(), std::bind(descending_comp, _1, _2, param_number));
}

void SearchableData::sort_descending_access(int param_number) {
    if (param_number == 11) {

    }

}

bool ascending_comp(ElementType first, ElementType second, int param_number) {
    return first.properties[param_number] > second.properties[param_number];
}

bool descending_comp(ElementType first, ElementType second, int param_number) {
    return first.properties[param_number] < second.properties[param_number];
}

bool ascending_comp_sum(ElementType first, ElementType second) {
    double first_sum = 0;
    double second_sum = 0;
    for (int i = 0; i < 10; i++) {
        first_sum += first.properties[i];
        second_sum += second.properties[i];
    }
    return first_sum > second_sum;
}

bool descending_comp_sum(ElementType first, ElementType second) {
    double first_sum = 0;
    double second_sum = 0;
    for (int i = 0; i < 10; i++) {
        first_sum += first.properties[i];
        second_sum += second.properties[i];
    }
    return first_sum < second_sum;
}