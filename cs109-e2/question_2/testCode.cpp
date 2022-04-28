#include "DynamicArray.h"

int main()
{
    DynamicArray dynamic_array(40);

    // add first 40 entries
    for (int i = 0; i < 40; i++)
    {
        dynamic_array.add(i);
    }

    // // test get() first time
    // std::cout << "Elem 5 befor any buff_change: " << data_ptr.get(5) << std::endl;
    // // test set() first time
    // data_ptr.set(5, BufferedChange::ADD, 6);
    // // test get() second time
    // std::cout << "Elem 5 after adding buff_change: " << data_ptr.get(5) << std::endl;
}