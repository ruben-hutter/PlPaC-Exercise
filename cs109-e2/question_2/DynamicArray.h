#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// #include <cmath>
#include <iostream>

// The Buffer's Element
class BufferedChange
{
    private:
        // operation to apply to value and element
        int op;
        // operand to apply operator to
        int* operand;
        // value in array to apply operator to
        int value;
        // gets the value of the element after changes
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
        BufferedChange(int* operand, enum Operator op, int value);
        // deconstructor
        ~BufferedChange();
        // executes the buffered change
        void execute();
};

// The Buffer
class LinkedList
{
    private:
        // head of list
        struct Node* head;
        // tail of list
        struct Node* tail;

    public:
        // node of linked list
        struct Node
        {
            BufferedChange bufferedChange;
            struct Node* next;
            struct Node* prev;
        };
        // constructor
        LinkedList();
        // destructor
        ~LinkedList();

        // append node at the end of an element related sequence
        // of operations and returns the pointer to the beginning
        // of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
        Node* append(BufferedChange* buff_change);
        // overwrite buffered change sequenze of element, and becomes
        // first of sequence.
        void overwrite(BufferedChange* buff_change);
        // executes buffered changes in this list
        void execute();
        // function that returns the value of an element that it
        // would have, if the buffered changes would be applied.
        int getValueOf(Node* elem_buff_ptr);

    private:
        // append to tail
        void appendTail(BufferedChange* buff_change);
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
        typedef struct
        {
            int* elem_arr_ptr;
            LinkedList::Node* elem_buff_ptr;
        } access_tuple;
        // access array for fast access to buffer elements
        access_tuple access_array[DEFAULT_SIZE];
        // first free position in access
        int position_in_access;
};

#endif