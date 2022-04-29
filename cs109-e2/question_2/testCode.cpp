#include "DynamicArray.h"

int main()
{
    DynamicArray dynamic_array(40);

    // add first 40 entries
    for (int i = 0; i < 40; i++)
    {
        dynamic_array.add(i);
    }

    // test get() first time
    std::cout << "Elem 5 befor any buff_change: " << dynamic_array.get(5) << std::endl;
    // print data structs
    dynamic_array.printDynArr();
    dynamic_array.printAccess();
    dynamic_array.buffer.printBuffer();
    // test set() first time
    dynamic_array.set(5, BufferedChange::ADD, 6);
    // test get() second time
    std::cout << "Elem 5 after adding buff_change: " << dynamic_array.get(5) << std::endl;
    // print data structs
    dynamic_array.printDynArr();
    dynamic_array.printAccess();
    dynamic_array.buffer.printBuffer();
}