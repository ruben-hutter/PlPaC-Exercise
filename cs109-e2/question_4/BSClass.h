#ifndef BS_CLASS_H
#define BS_CLASS_H

#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

template <typename T>
class BSClass {
    e_list = std::list<T>;
public:
    void sort();
    void add_elem(T elem);
    void erase_elem(int index);
    T get_elem(int index);
    void add(int index, T operand);
    void subtract(int index, T operand);
    void mult(int index, T operand);
    void div(int index, T operand);
    void print();
};

#endif