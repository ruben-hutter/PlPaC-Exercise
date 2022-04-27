#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cmath>
#include <iostream>
#include <array>
#include <list>
using namespace std;

class BufferedChange {
private:
    // operation to apply to value and element
    int op;
    // operand to apply operator to
    int* operand;
    // value in array to apply operator to
    int value;
    // gets the current value of the element in the array
    int getValueOf();
    // applies the add operator
    int add();
    // applies the subtract aoperator
    int subtract();
    // aplies the multiplication operator
    int multiply();
    // applies the division multiplicator
    int divide();
    // enum storing all available operations
    enum Operator {ADD = 0, SUBTRACT = 1, MULT = 2, DIV = 3};

public:
    // constructor
    BufferedChange();
    // deconstructor
    ~BufferedChange();
    // executes the buffered change
    void execute();
};

class DynamicArray {
    private:
        float ALLOC_SIZE = 5/4.0f;
        float FREE_SIZE = 1/2.0f;
        float TRIM_SIZE = 3/2.0f;
        int DEFAULT_SIZE = 10;

    public:
        DynamicArray::DynamicArray(int initialSize);
        DynamicArray::~DynamicArray();

        // return element
        int get(int index);
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
        // pointer to dynamic array
        int* data_ptr;
        // number of elements in dynamic array
        int size;
        // size/length of dynamic array
        int avail;
        // linked list
        std::list<BufferedChange> buffer;
        //access tuple
        typedef std::tuple<int*, int*> access_tuple;
        std::array<access_tuple, 10> access_array;
};

#endif

/** TODO
 * [x] init buffer in dynamic array constructor
 * [ ] find out what ddatatypes are needed in the tuple at L78
 *      related info:
 *      an access pointer field (static array of tuples of elements with changes buffered
 *      and a direct link to the its latest value or relevant sequence of changes in the
 *      buffer
 * 
 *      The access list is a list of tuples, an element identifier (pointer or number) and
 *      a pointer to the most recent value of/sequence of changes to that element.
 *      The access list has 10 entries, which is the maximum allowed number of buffered
 *      changes.
 * [x] create static array of size 10 of the required tuple (see above)
 * [] init access tuple thing in dyn. arr. constructor
 * [] implement buffering into set method
 * [] implement get value (ref to exercise p.6)
 * [] implement function in buffer change
 * [] some more stuff we'll find out later
 **/