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
    std::cout << "before set array[5]: " << dynamic_array.get(5) << std::endl;
    // test set() first time
    dynamic_array.set(5, BufferedChange::ADD, 5);
    // test get() second time
    std::cout << "after set array[5]: " << dynamic_array.get(5) << std::endl;
}