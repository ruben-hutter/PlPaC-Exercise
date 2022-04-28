#include "DynamicArray.h"

// constructor: initialize list with 0-operation as root/head
LinkedList::LinkedList()
{
    Node* zero_op = new Node;
    head = zero_op;
    tail = zero_op;
}

// destructor
LinkedList::~LinkedList()
{
    // TODO
}

// append node at the end of an element related sequence
// of operations and returns the pointer to the beginning
// of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
LinkedList::Node* LinkedList::append(BufferedChange* buff_change)
{
    // TODO
    Node* actual_sequence_start_node;
    // 1. check if elem in access
    // 2a. if so start iterating buffer from elem_buff_ptr
    //     and append to the end of sequence the new buff_change
    // 2b. if not append to tail and add to access_array
    //     -> appendTail()

    Node* tmp = new Node;
    tmp->next = NULL;

    tail->next = tmp;
    tail = tail->next;
    return actual_sequence_start_node;
}

// overwrite buffered change sequenze of element, and becomes
// first of sequence.
void LinkedList::overwrite(BufferedChange* buff_change)
{
    // TODO
    // 1. check if elem in access (check if in buffer)
    // 2a. link prev of sequence start to new buff_change, and next of
    //     new buff_change to first elem of next sequence (see access_array)
    // 2b. if not, append to tail and add to access_array
    //     -> appendTail()
}

// append to tail
void LinkedList::appendTail(BufferedChange* buff_change)
{
    // TODO
}

// executes buffered changes in this list
void LinkedList::execute()
{
    // TODO
}

// function that returns the value of an element that it
// would have, if the buffered changes would be applied.
int LinkedList::getValueOf(Node* elem_buff_ptr)
{
    // TODO
    int value;
    LinkedList::Node* actual_elem;
    // iterate from elem_buff_ptr to end of sequence
    // and update value
    return value;
}