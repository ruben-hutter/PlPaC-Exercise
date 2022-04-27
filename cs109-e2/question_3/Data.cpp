#include "Data.h"

void Data::remove(int uid){
    for (list<ElementType>::iterator it=data_list.begin(); it!=data_list.end(); it++) {
        if (it->uid = uid){
            data_list.erase(it);
        }
    }
}

void Data::add(ElementType element){
    data_list.push_front(element);
}

void Data::empty(){
    data_list.clear();
}