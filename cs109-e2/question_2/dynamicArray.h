#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
    private:
        float ALLOC_SIZE = 5/4.0f;
        float FREE_SIZE = 1/2.0f;

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

        // allocate memory 5/4 size
        void grow();

        // free memory size/2
        void shrink();
    
    private:
        DynamicArray* data_ptr;
        int size;
        int avail;
        // priority list
        Buffer* buffer;
        access;
};

#endif