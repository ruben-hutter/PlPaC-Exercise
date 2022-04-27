// dynamic array implementation
#include "DynamicArray.h"

DynamicArray::DynamicArray(int initialSize)
{
    if (initialSize > 0)
    {
        data_ptr = new int[initialSize];
        return;
    }
    data_ptr = new int[DEFAULT_SIZE];
}

DynamicArray::~DynamicArray()
{
    delete[] data_ptr;
}

// gets specific element
int DynamicArray::get(int index)
{
    // check if element in access
    // iterate over buffer with get value of
    // return
    // ELSE
    // get elem from dyn array
    if (index < 0 || index >= size)
    {
        return NULL;
    }
    return data_ptr[index];
}

// change element
void DynamicArray::set(int index, BufferedChange::Operator op, int value)
{
    if (index < 0 || index >= size) {
        return;
    }
    // create new buffered change
    BufferedChange* bc = new BufferedChange(&data_ptr[index], op, value);
    // put change in buffer
    appendToBuffer(bc);
    // create access entry if not already contained ()
    for (int i = 0; i < 10; i++) {
        if (bc->operand != &data_ptr[index]) {
            continue;
        }
    }
}

// appends the specified change to the buffer
void DynamicArray::appendToBuffer(BufferedChange* change) {

}

// add an element
void DynamicArray::add(int element)
{
    grow();
    data_ptr[size] = element;
    size++;
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
        int *new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i = i++)
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
        int *new_arr = new int[new_size];
        // copy data
        for (int i = 0; i < avail; i = i++)
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
BufferedChange::BufferedChange(int* operand, Operator op, int value) {

}

// deconstructor
BufferedChange::~BufferedChange() {

}

// gets the current value of the element in the array
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
void BufferedChange::execute() {
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