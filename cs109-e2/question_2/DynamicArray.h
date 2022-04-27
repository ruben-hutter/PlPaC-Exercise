#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "LinkedList.h"
#include <cmath>
#include <iostream>

using namespace std;

class BufferedChange
{
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

    public:
        // enum storing all available operations
        enum Operator {NULL_ = 0, ADD = 1, SUBTRACT = 2, MULT = 3, DIV = 4};
        // constructor
        BufferedChange(int* operand, BufferedChange::Operator op, int value);
        // deconstructor
        ~BufferedChange();
        // executes the buffered change
        void execute();
        // operation to apply to value and element
        int op;
        // operand to apply operator to
        int* operand;
        // value in array to apply operator to
        int value;
};

class DynamicArray
{
    private:
        static const float ALLOC_SIZE = 5/4.0f;
        static const float FREE_SIZE = 1/2.0f;
        static const float TRIM_SIZE = 3/2.0f;
        static const int DEFAULT_SIZE = 10;

    public:
        DynamicArray(int initialSize);
        ~DynamicArray();

        // return element
        int get(int index);
        // return value of element
        int getValueBuff(int* elem_ptr_buff);
        // change element
        void set(int index, BufferedChange::Operator op, int value);
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
        // linked list buffer
        LinkedList buffer;
        // access tuple: <elem_arr_ptr, elem_buff_ptr>
        typedef struct access_tuple {
            int* elem_arr_ptr;
            int* elem_buff_ptr;
        };
        // access array for fast access to buffer elements
        access_tuple access_array[DEFAULT_SIZE];
        // first free position in access
        int position_in_access;
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