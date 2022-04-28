#ifndef MEAN_DIFF_DATA_H
#define MEAN_DIFF_DATA_H

#include "SearchableData.h"
#include "OverloadedElementType.h"

using namespace std;

class MeanDiffData: public SearchableData {
    std::list<OverloadedElementType> data_list;
    OverloadedElementType mean_elem;
    void mean_diff();
    OverloadedElementType getMeanElem();
    void sort_ascending_search(int param_number);
    void sort_ascending_access(int param_number);
    void sort_descending_search(int param_number);
    void sort_descending_access(int param_number);
    bool ascending_comp(OverloadedElementType first, OverloadedElementType second, int param_number);
    bool descending_comp(OverloadedElementType first, OverloadedElementType second, int param_number);
    OverloadedElementType get(int uid);
    void remove(int uid);
    void add(OverloadedElementType element);
    void empty();
};

#endif