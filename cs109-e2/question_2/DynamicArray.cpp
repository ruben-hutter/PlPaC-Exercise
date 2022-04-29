// dynamic array implementation
#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialSize)
{
    // initialize dynamic array of data
    if (initialSize < 0)
    {
        data_ptr = new int[DEFAULT_SIZE];
        avail = DEFAULT_SIZE;
    }
    else
    {
        data_ptr = new int[initialSize];
        avail = initialSize;
    }
    // initialize access index to first free position
    access_array = new access_tuple[DEFAULT_SIZE];
    position_in_access = 0;
    size = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] data_ptr;
}

// gets specified element most recent value
int DynamicArray::get(int index)
{
    if (index < 0 || index >= size)
    {
        return -1;
    }
    // check if element in access
    int* elem_arr_ptr = &data_ptr[index];
    int at_index = checkAccess(elem_arr_ptr);
    LinkedList::Node* elem_buff_ptr = access_array[at_index].elem_buff_ptr;
    if (at_index >= 0)
    {
        // iterate over buffer and return value for element
        return buffer.getValueOf(elem_buff_ptr);
    }
    // get elem from dyn array
    return data_ptr[index];
}

// change element
void DynamicArray::set(int index, BufferedChange::Operator op, int value)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    // create new buffered change
    BufferedChange* buff_change = new BufferedChange(&data_ptr[index], op, value);
    // create new node
    LinkedList::Node* new_buff_elem = new LinkedList::Node;
    // link buff_change to node
    new_buff_elem->bufferedChange = buff_change;
    // check if element in access
    int* elem_arr_ptr = &data_ptr[index];
    int at_index = checkAccess(elem_arr_ptr);
    if (at_index < 0)
    {
        // new access_tuple for elem
        access_tuple* at = new access_tuple;
        at->elem_arr_ptr = elem_arr_ptr;
        at->elem_buff_ptr = new_buff_elem;
        // add access_tuple to access_array and increment position
        access_array[position_in_access++] = *at;
        // append to tail of buffer
        buffer.appendTail(new_buff_elem);
    }
    else
    {
        LinkedList::Node* elem_buff_ptr = access_array[at_index].elem_buff_ptr;
        // append to sequence
        buffer.append(new_buff_elem, elem_buff_ptr);
    }
}

// add an element
void DynamicArray::add(int element)
{
    grow();
    data_ptr[size++] = element;
}

// remove last element from of array
void DynamicArray::remove()
{
    // emtpy array
    if (size == 0)
    {
        std::cout << "Array is empty!" << std::endl;
        return;
    }
    int* elem_to_delete = &data_ptr[size - 1];
    *elem_to_delete = 0;
    shrink();
    // check if operations buffered for elem and remove them if so
    int idx_in_access = checkAccess(elem_to_delete);
    if (idx_in_access >= 0)
    {
        // delete buffer sequence
        access_tuple access_elem = access_array[idx_in_access];
        buffer.remove(access_elem.elem_buff_ptr);
        // delete access_array entry
        removeAccess(idx_in_access);
    }
}

// executes the buffered changes
void DynamicArray::trim()
{
    // exec all buffer changes
    buffer.execute();
    // empty access_array and reset idx_ptr
    clearAccess();
}

// overwrite elem buffered changes with new buffer entry
void DynamicArray::overwrite(int index, BufferedChange::Operator op, int value)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    BufferedChange* buff_change = new BufferedChange(&data_ptr[index], op, value);
    // create new node
    LinkedList::Node* new_buff_elem = new LinkedList::Node;
    // link buff_change to node
    new_buff_elem->bufferedChange = buff_change;
    // check if element in access
    int* elem_arr_ptr = &data_ptr[index];
    int at_index = checkAccess(elem_arr_ptr);
    if (at_index < 0)
    {
        // new access_tuple for elem
        access_tuple* at = new access_tuple;
        at->elem_arr_ptr = elem_arr_ptr;
        at->elem_buff_ptr = new_buff_elem;
        // add access_tuple to access_array and increment position
        access_array[position_in_access++] = *at;
    }
    else
    {
        // if yes, free memory for actual entries and set pointer
        //      of prev_elem to new_buff_change and pointer of
        //      new_buff_change to next sequence elem or null if last (tail)
        // create new buffered change
        LinkedList::Node* elem_buff_ptr = access_array[at_index].elem_buff_ptr;
        // remove actual sequence
        buffer.remove(elem_buff_ptr);
    }
    // append to tail of buffer
    buffer.appendTail(new_buff_elem);
}

// increases the memory by the specified value
void DynamicArray::grow()
{
    if (size == avail)
    {
        // exec all buffer changes
        trim();
        // alloc space for new array
        int new_size = ceil(ALLOC_SIZE * avail);
        int* new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i++)
        {
            new_arr[i] = data_ptr[i];
        }
        // free old memory
        delete[] data_ptr;
        data_ptr = new_arr;
        avail = new_size;
    }
}

// decreases the memory by the specified value
void DynamicArray::shrink()
{
    if (size == avail * FREE_SIZE)
    {
        // exec all buffer changes
        trim();
        // alloc space for new array
        int new_size = ceil(FREE_SIZE * avail);
        int* new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i++)
        {
            new_arr[i] = data_ptr[i];
        }
        // free old memory
        delete[] data_ptr;
        data_ptr = new_arr;
        avail = new_size;
    }
}

// check if element in access and return index in access or -1
int DynamicArray::checkAccess(int* elem_arr_ptr)
{
    for (int i = 0; i < position_in_access; i++)
    {
        int* access_elem_i = access_array[i].elem_arr_ptr;
        if (elem_arr_ptr == access_elem_i)
        {
            return i;
        }
    }
    return -1;
}

// remove access_array entry
void DynamicArray::removeAccess(int index)
{
    // temp access_array
    access_tuple* tmp_access = new access_tuple[DEFAULT_SIZE];
    // temp ptr
    int tmp_ptr = 0;
    for (int i = 0; i < position_in_access; i++)
    {
        if (i != index)
        {
            tmp_access[tmp_ptr++] = access_array[i];
        }
    }
    // free memory
    delete[] access_array;
    access_array = tmp_access;
    // decrese access ptr
    position_in_access--;
}

// clear access_array
void DynamicArray::clearAccess()
{
    // iterate access_array
    for (int i = 0; i < position_in_access; i++)
    {
        // free memory
        delete &access_array[i];
    }
    position_in_access = 0;
}

// print access_array (for debugging)
void DynamicArray::printAccess()
{
    std::cout << "access_array: ";
    for (int i = 0; i < position_in_access; i++)
    {
        std::cout << *access_array[i].elem_arr_ptr << " ";
    }
    std::cout << std::endl;
}

// print dyn_array (for debugging)
void DynamicArray::printDynArr()
{
    std::cout << "dyn_array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data_ptr[i] << " ";
    }
    std::cout << std::endl;
}

// constructor
BufferedChange::BufferedChange(int* operand, Operator op, int value)
{
    BufferedChange::operand = operand;
    BufferedChange::op = op;
    BufferedChange::value = value;
}

// deconstructor
BufferedChange::~BufferedChange()
{
    // nothing to do
}

// gets the value of the element after changes
int BufferedChange::getValueOf()
{
    switch (op)
    {
    case 1:
        return add();
    case 2:
        return subtract();
    case 3:
        return multiply();
    case 4:
        return divide();
    }
    return -1;
}

// executes the buffered change
void BufferedChange::execute()
{
    *operand = getValueOf();
}

// applies the add operator
int BufferedChange::add()
{
    return *operand + value;
}

// applies the subtract aoperator
int BufferedChange::subtract()
{
    return *operand - value;
}

// aplies the multiplication operator
int BufferedChange::multiply()
{
    return *operand * value;
}

// applies the division multiplicator
int BufferedChange::divide()
{
    return *operand / value;
}
