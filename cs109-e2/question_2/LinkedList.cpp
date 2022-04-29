#include "DynamicArray.h"

// constructor: initialize list with 0-operation as root/head
LinkedList::LinkedList()
{
    // initialize head with zero_op node
    Node* zero_op = new Node;
    zero_op->bufferedChange = NULL;
    zero_op->next = NULL;
    zero_op->prev = NULL;
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
void LinkedList::overwriteSequence(Node* new_buff_elem)
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
    Node* actual_elem = head->next;
    Node* elem_to_delete;
    while (actual_elem != NULL)
    {
        actual_elem->bufferedChange->execute();
        elem_to_delete = actual_elem;
        actual_elem = actual_elem->next;
        // free memory
        delete elem_to_delete->bufferedChange;
        delete elem_to_delete;
    }
    // reset empty list pointers
    head->next = NULL;
    tail = head;
}

// function that returns the value of an element that it
// would have, if the buffered changes would be applied.
int LinkedList::getValueOf(Node* elem_buff_ptr)
{
    // save elem_buff_ptr's operand
    int* original_arr_operand_ptr = elem_buff_ptr->bufferedChange->operand;
    // value of operand
    int original_arr_operand = *original_arr_operand_ptr;
    int return_value;

    // actual elem
    Node* actual_elem = elem_buff_ptr;
    // iterate from elem_buff_ptr to end of sequence
    while (actual_elem != NULL)
    {
        if (actual_elem->bufferedChange->operand != original_arr_operand_ptr)
        {
            break;
        }
        *original_arr_operand_ptr = actual_elem->bufferedChange->getValueOf();
        actual_elem = actual_elem->next;
    }
    // save updated value
    return_value = *original_arr_operand_ptr;
    // reset to original value
    *original_arr_operand_ptr = original_arr_operand;
    return return_value;
}

// remove a sequence of buffered changes
void LinkedList::remove(Node* elem_buff_ptr)
{
    // save elem_buff_ptr's operand
    int* elem_buff_operand = elem_buff_ptr->bufferedChange->operand;
    // save prev elem
    Node* elem_prev = elem_buff_ptr->prev;
    // actual elem
    Node* actual_elem = elem_buff_ptr;
    // elem to delete
    Node* elem_to_delete;
    // iterate from elem_buff_ptr to end of sequence
    while (actual_elem != NULL)
    {
        if (actual_elem->bufferedChange->operand != elem_buff_operand)
        {
            // set new pointers without sequence
            actual_elem->prev = elem_prev;
            elem_prev->next = actual_elem;
            break;
        }
        // check if end of list
        if (actual_elem == tail)
        {
            // update pointers
            tail = elem_prev;
            tail->next = NULL;
        }
        elem_to_delete = actual_elem;
        actual_elem = actual_elem->next;
        delete elem_to_delete->bufferedChange;
        delete elem_to_delete;
    }
}

// print list (for debugging)
void LinkedList::printBuffer()
{
    Node* actual_elem = head->next;
    std::cout << "buffer: ";
    while (actual_elem != NULL)
    {
        std::cout << *(actual_elem->bufferedChange->operand) << " ";
        actual_elem = actual_elem->next;
    }
    std::cout << std::endl;
}