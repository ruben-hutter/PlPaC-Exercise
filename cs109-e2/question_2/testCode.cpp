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
    std::cout << "before set array[5]: " << dynamic_array.get(39) << std::endl;
    // test set() first time
    dynamic_array.set(39, BufferedChange::ADD, 1);
    // test get() second time
    std::cout << "after set array[5]: " << dynamic_array.get(39) << std::endl;
    // test set() second time
    dynamic_array.set(39, BufferedChange::DIV, 2);

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // test trim()
    dynamic_array.trim();

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();
}