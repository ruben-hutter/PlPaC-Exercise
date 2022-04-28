#include <BSClass.h>

template <typename T>
void BSClass<T>::sort() {
    e_list.sort();
}

template <typename T>
void BSClass<T>::add_elem(T elem) {
    e_list.push_back(elem);
}

template <typename T>
void BSClass<T>::erase_elem(int index){
    e_list.erase(index);
}

template <typename T>
T BSClass<T>::get_elem(int index) {
    auto e_ptr = e_list.begin();
    std::advance(e_ptr, index):
    return *e_ptr;
}

template <typename T>
void BSClass<T>::add(int index, T operand) {
    get_elem(index) += operand;
    sort();
}

template <typename T>
void BSClass<T>::subtract(int index, T operand) {
    get_elem(index) -= operand;
    sort();
}

template <typename T>
void BSClass<T>::mult(int index, T operand) {
    get_elem(index) *= operand;
    sort();
}

template <typename T>
void BSClass<T>::div(int index, T operand) {
    get_elem(index) /= operand;
    sort();
}

template <typename T>
void BSClass<T>::print() {
    for (auto e : e_list)
        std::cout << v << "\n";
}
