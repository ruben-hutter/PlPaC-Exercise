#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
    private:
        struct Node
        {
            BufferedChange bufferedChange;
            struct Node* next;
        };
        Node* head;

    public:
        // constructor
        LinkedList();
        // destructor
        ~LinkedList();

        // append node at the end of an element related sequence
        // of operations and returns the pointer to the beginning
        // of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
        Node* append(Node n);
        // overwrite buffered change sequenze of element, and becomes
        // first of sequence.
        void overwrite();
        // executes buffered changes in this list
        void execute();
        // function that returns the value of an element that it
        // would have, if the buffered changes would be applied.
        int getValueOf();
};

#endif