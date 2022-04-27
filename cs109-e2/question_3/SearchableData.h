#ifndef SEARCHABLE_ABDATA_H
#define SEARCHABLE_DATA_H

#include "Data.h"
#include <algorithm>
#include <functional>

using namespace std;

class SearchableData: public Data {
    void sort_ascending_search(int param_number);
    void sort_ascending_access(int param_number);
    void sort_descending_search(int param_number);
    void sort_descending_access(int param_number);
    bool ascending_comp(ElementType first, ElementType second, int param_number);
    bool descending_comp(ElementType first, ElementType second, int param_number);
};

#endif