// dynamic array implementation
#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialSize)
{
    // initialize dynamic array of data
    if (initialSize < 0)
    {
        data_ptr = new int[DEFAULT_SIZE];
        return;
    }
    data_ptr = new int[initialSize];
    // initialize access index to first free position
    position_in_access = 0;
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
        return NULL;
    }
    // check if element in access
    for (int i = 0; i < position_in_access; i++)
    {
        int* elem_arr_ptr = access_array[i].elem_arr_ptr;
        if (elem_arr_ptr == &data_ptr[index])
        {
            // iterate over buffer and return value for element
            return buffer.getValueOf(access_array[i].elem_buff_ptr);
        }
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
    BufferedChange* bc = new BufferedChange(&data_ptr[index], op, value);
    // put change in buffer and get sequence ptr in buffer
    LinkedList::Node* elem_buff_ptr = buffer.append(bc);
    // create access entry if not already contained
    bool found = false;
    for (int i = 0; i < position_in_access; i++)
    {
        int* elem_arr_ptr = access_array[i].elem_arr_ptr;
        if (elem_arr_ptr == &data_ptr[index])
        {
            found = true;
        }
    }
    if (!found)
    {
        // new access_tuple for elem
        access_tuple at;
        at.elem_arr_ptr = &data_ptr[index];
        at.elem_buff_ptr = elem_buff_ptr;
        // add access_tuple to access_array and increment position
        access_array[position_in_access++] = at;
    }
}

// add an element
void DynamicArray::add(int element)
{
    grow();
    data_ptr[size++] = element;
}

// remove element form the end of the array
void DynamicArray::remove()
{
    // emtpy array
    if (size == 0)
    {
        cout << "Array is empty!" << endl;
        return;
    }
    data_ptr[size--] = 0;
    shrink();
}

// executes the buffered changes at sets the available memory to 3/2
void DynamicArray::trim()
{
    // exec all buffer changes
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
    // TODO
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
        return NULL;
    }
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
