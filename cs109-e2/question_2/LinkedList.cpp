#include "DynamicArray.h"

// constructor: initialize list with 0-operation as root/head
LinkedList::LinkedList()
{
    // initialize head with zero_op node
    Node* zero_op = new Node;
    head = zero_op;
    tail = zero_op;
}

// destructor
LinkedList::~LinkedList()
{
    delete head;
}

// append node at the end of an element related sequence
// of operations and returns the pointer to the beginning
// of this sequence. [A,A,B,C] -> append(A), return ptr to A[0]
LinkedList::Node* LinkedList::append(Node* new_buff_elem, Node* start_of_sequence)
{
    // iterate over buffer starting by start_of_sequence
    LinkedList::Node* actual_elem = start_of_sequence;
    while (actual_elem != NULL)
    {
        if (actual_elem->bufferedChange->operand != new_buff_elem->bufferedChange->operand)
        {
            // set links of new element
            new_buff_elem->next = actual_elem;
            new_buff_elem->prev = actual_elem->prev;

            // set links of prev and next elem of new
            actual_elem->prev->next = new_buff_elem;
            actual_elem->prev = new_buff_elem;
            return start_of_sequence;
        }
        actual_elem = actual_elem->next;
    }
    appendTail(new_buff_elem);
    return start_of_sequence;
}

// overwrite buffered change sequenze of element, and becomes
// first of sequence.
void LinkedList::overwrite()
{
    // TODO
    // 1. check if elem in access (check if in buffer)
    // 2a. link prev of sequence start to new buff_change, and next of
    //     new buff_change to first elem of next sequence (see access_array)
    // 2b. if not, append to tail and add to access_array
    //     -> appendTail()
}

// append to tail
void LinkedList::appendTail(Node* new_buff_elem)
{
    // set links of new element
    new_buff_elem->prev = tail;
    new_buff_elem->next = NULL;

    // move tail
    tail->next = new_buff_elem;
    tail = tail->next;
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
    int value = 0;
    Node* actual_elem = elem_buff_ptr;
    // iterate from elem_buff_ptr to end of sequence
    while (actual_elem != NULL)
    {
        if (actual_elem->bufferedChange->operand != elem_buff_ptr->bufferedChange->operand)
        {
            break;
        }
        value += actual_elem->bufferedChange->getValueOf();
        actual_elem = actual_elem->next;
    }
    // and update value
    return value;
}

// remove a sequence of buffered changes
void LinkedList::remove(Node* elem_buff_ptr)
{
}

// print list
void LinkedList::print()
{
    Node* actual_elem = head->next;
    while (actual_elem != NULL)
    {
        std::cout << *(actual_elem->bufferedChange->operand) << " ";
        actual_elem = actual_elem->next;
    }
    std::cout << std::endl;
}