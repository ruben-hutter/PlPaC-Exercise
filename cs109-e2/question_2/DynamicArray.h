#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cmath>
#include <iostream>

// The Buffer's Element
class BufferedChange
{
    private:
        // operation to apply to value and element
        int op;
        // value in array to apply operator to
        int value;
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
        BufferedChange(int* operand, enum Operator op, int value);
        // deconstructor
        ~BufferedChange();
        // operand to apply operator to
        int* operand;
        // gets the value of the element after changes
        int getValueOf();
        // executes the buffered change
        void execute();
};

// The Buffer
class LinkedList
{
    public:
        // node of linked list
        struct Node
        {
            BufferedChange* bufferedChange;
            struct Node* next;
            struct Node* prev;
        };
        // head of list
        Node* head;
        // tail of list
        Node* tail;

    public:
        // constructor
        LinkedList();
        // destructor
        ~LinkedList();

        // append node at the end of an element related sequence
        // of operations and returns the pointer to the beginning
        // of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
        Node* append(Node* new_buff_elem, Node* start_of_sequence);
        // overwrite buffered change sequenze of element, and becomes
        // first of sequence.
        void overwrite();
        // executes buffered changes in this list
        void execute();
        // function that returns the value of an element that it
        // would have, if the buffered changes would be applied.
        int getValueOf(Node* elem_buff_ptr);
        // append to tail
        void appendTail(Node* new_buff_elem);
        // remove a sequence of buffered changes
        void remove(Node* elem_buff_ptr);
        // print list (for debugging)
        void printBuffer();
};

// The Dynamic Array
class DynamicArray
{
    private:
        constexpr static const float ALLOC_SIZE = 5/4.0f;
        constexpr static const float FREE_SIZE = 1/2.0f;
        constexpr static const float TRIM_SIZE = 3/2.0f;
        static const int DEFAULT_SIZE = 10;

    public:
        DynamicArray(int initialSize);
        ~DynamicArray();

        // return element
        int get(int index);
        // change element
        void set(int index, BufferedChange::Operator op, int value);
        // add an element
        void add(int element);
        // remove element from the end of the array
        void remove();
        // executes the buffered changes
        void trim();
        // allocate memory 5/4 size
        void grow();
        // free memory size/2
        void shrink();

        // DEBUGGING
        // print access_array (for debugging)
        void printAccess();
        // print dyn_array (for debugging)
        void printDynArr();
        // PUBLIC ONLY FOR DEBUGGING
        // linked list buffer
        LinkedList buffer;

    private:
        // pointer to dynamic array
        int* data_ptr;
        // number of elements in dynamic array
        int size;
        // size/length of dynamic array
        int avail;
        // access tuple: <elem_arr_ptr, elem_buff_ptr>
        typedef struct
        {
            int* elem_arr_ptr;
            LinkedList::Node* elem_buff_ptr;
        } access_tuple;
        // access array for fast access to buffer elements
        access_tuple* access_array;
        // first free position in access
        int position_in_access;
        // check if element in access
        int checkAccess(int* elem_arr_ptr);
        // remove access_array entry
        void removeAccess(access_tuple access_elem, int index);
        // clear access_array
        void clearAccess();
};

#endif