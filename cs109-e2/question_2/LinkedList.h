#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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
            BufferedChange::BufferedChange bufferedChange;
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
        void overwrite();
        // executes buffered changes in this list
        void execute();
        // function that returns the value of an element that it
        // would have, if the buffered changes would be applied.
        int getValueOf(Node* elem_buff_ptr);

    private:
        // append to tail
        void appendTail(BufferedChange* buff_change);
};

#endif