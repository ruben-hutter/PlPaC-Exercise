#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
    public:
        DynamicArray::DynamicArray(int initialSize);
        DynamicArray::~DynamicArray();

        // return element
        int get();

        // change element
        void set(int position, int element);

        // add an element
        void add(int element);

        // remove element
        void remove();

        // executes the buffered changes at sets the available memory to 3/2
        void trim();
    
    private:
        DynamicArray* data_ptr;
};

#endif