// dynamic array implementation
#include "dynamicArray.h"

DynamicArray::DynamicArray(int initialSize) {
    if (initialSize > 0) {
        data_ptr = new int[initialSize];
        return;
    }
    data_ptr = new int[DEFAULT_SIZE];
}

DynamicArray::~DynamicArray() {
    delete [] data_ptr;
}

// gets specific element
int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        return NULL;
    }
    return data_ptr[index];
}

// change element
void DynamicArray::set(int position, int element) {

}

// add an element
void DynamicArray::add(int element) {
    grow();
    data_ptr[size] = element;
    size++;
}

// remove element form the end of the array
void DynamicArray::remove() {
    // emtpy array
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    data_ptr[size--] = 0;
    shrink();
}

// executes the buffered changes at sets the available memory to 3/2
void DynamicArray::trim(){
    // alloc space for new array
    int new_size = ceil(TRIM_SIZE*avail);
    int* new_arr = new int[new_size];
    // copy data
    for (int i = 0; i < avail; i = i++) {
        new_arr[i] = data_ptr[i];
    }
    // free old memory
    delete [] data_ptr;
    data_ptr = new_arr;
    avail = new_size;

}

// increases the memory by the specified value
void DynamicArray::grow(){
    if (size == avail) {
        // alloc space for new array
        int new_size = ceil(ALLOC_SIZE*avail);
        int* new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i = i++) {
            new_arr[i] = data_ptr[i];
        }
        // free old memory
        delete [] data_ptr;
        data_ptr = new_arr;
        avail = new_size;
    }
}

// decreases the memory by the specified value
void DynamicArray::shrink(){
    if (size == avail * FREE_SIZE) {
        // alloc space for new array
        int new_size = ceil(FREE_SIZE*avail);
        int* new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i = i++) {
            new_arr[i] = data_ptr[i];
        }
        // free old memory
        delete [] data_ptr;
        data_ptr = new_arr;
        avail = new_size;
    }
}