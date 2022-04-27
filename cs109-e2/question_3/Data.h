#ifndef DATA_H
#define DATA_H
#include <list>
#include "ElementType.h"

using namespace std;

class Data {
    std::list<ElementType> data_list;
    ElementType get(int uid);
    void remove(int uid);
    void add(ElementType element);
    void empty();
};

#endif