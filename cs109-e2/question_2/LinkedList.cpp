#include "LinkedList.h"

// constructor: initialize list with 0-operation as root/head
LinkedList::LinkedList()
{
    Node zero_op;
    head = &zero_op;
}

// destructor
LinkedList::~LinkedList()
{
    // TODO
}

// append node at the end of an element related sequence
// of operations and returns the pointer to the beginning
// of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
LinkedList::Node* LinkedList::append(LinkedList::Node n)
{
    // TODO
    return NULL;
}

// overwrite buffered change sequenze of element, and becomes
// first of sequence.
void LinkedList::overwrite()
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
int LinkedList::getValueOf()
{
    // TODO
}