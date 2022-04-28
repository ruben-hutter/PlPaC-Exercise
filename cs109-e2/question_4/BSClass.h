#ifndef BS_CLASS_H
#define BS_CLASS_H

#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

template <typename T>
class BSClass {
    std::list<T> e_list;
public:
    void sort() {
        e_list.sort();
    };

    void add_elem(T elem) {
        e_list.push_back(elem);
    };

    void erase_elem(int index) {
        e_list.erase(index);
    };

    void remove_first(T elem) {
        auto it = std::find(e_list.begin(), e_list.end(), 3);
        if (it != e_list.end()) {
            e_list.erase(it);
        }
    }

    T get_elem(int index) {
        auto e_ptr = e_list.begin();
        std::advance(e_ptr, index);
        return *e_ptr;
    };

    void add(int index, T operand) {
        T e = get_elem(index);
        add_elem(e + operand);
        remove_first(e);
        sort();
    };

    void subtract(int index, T operand) {
        T e = get_elem(index);
        add_elem(e - operand);
        remove_first(e);
        sort();
    };

    void mult(int index, T operand) {
        T e = get_elem(index);
        add_elem(e * operand);
        remove_first(e);
        sort();
    };

    void div(int index, T operand) {
        T e = get_elem(index);
        add_elem(e / operand);
        remove_first(e);
        sort();
    };

    void print() {
        for (auto e : e_list)
            std::cout << +e << "\n";
    };
};

#endif