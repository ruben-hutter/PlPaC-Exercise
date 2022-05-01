#include "DynamicArray.h"

int main()
{
    DynamicArray dynamic_array(40);

    // add first 40 entries
    for (int i = 0; i < 40; i++)
    {
        dynamic_array.add(i);
    }

    // print
    std::cout << "Initial array with 40 elem" << std::endl;
    dynamic_array.printDynArr();

    // add 5 elem
    for (int i = 0; i < 5; i++)
    {
        dynamic_array.add(i);
    }

    // print
    std::cout << "Added 5 elem" << std::endl;
    dynamic_array.printDynArr();

    // remove 5 elem
    for (int i = 0; i < 5; i++)
    {
        dynamic_array.remove();
    }

    // print
    std::cout << "Removed 5 elem" << std::endl;
    dynamic_array.printDynArr();

    // add 50 elem
    for (int i = 0; i < 50; i++)
    {
        dynamic_array.add(i);
    }

    // print
    std::cout << "Added 50 elem" << std::endl;
    dynamic_array.printDynArr();

    // remove 50 elem
    for (int i = 0; i < 50; i++)
    {
        std::cout << "removed " << i << " elem" << std::endl;
        dynamic_array.remove();
    }

    // print
    std::cout << "Removed 50 elem" << dynamic_array.size << std::endl;
    dynamic_array.printDynArr();

    // // test get() first time
    // std::cout << "before set array[5]: " << dynamic_array.get(39) << std::endl;
    // // test set() first time
    // dynamic_array.set(39, BufferedChange::ADD, 1);
    // // test get() second time
    // std::cout << "after set array[5]: " << dynamic_array.get(39) << std::endl;
    // // test set() second time
    // dynamic_array.set(39, BufferedChange::DIV, 2);

    // // print every data structure
    // dynamic_array.printDynArr();
    // dynamic_array.buffer.printBuffer();
    // dynamic_array.printAccess();

    // // test trim()
    // dynamic_array.trim();

    // // print every data structure
    // dynamic_array.printDynArr();
    // dynamic_array.buffer.printBuffer();
    // dynamic_array.printAccess();


    // TEST THAT FAILS
    // // add
    // dynamic_array.add(1);
    // dynamic_array.add(2);
    // dynamic_array.add(1);
    // dynamic_array.add(2);

    // // print
    // std::cout << "avail: " << dynamic_array.avail << std::endl;
    // std::cout << "size: " << dynamic_array.size << std::endl;
    // dynamic_array.printDynArr();

    // // remove
    // dynamic_array.remove();
    // dynamic_array.remove();

    // // print
    // std::cout << "avail: " << dynamic_array.avail << std::endl;
    // std::cout << "size: " << dynamic_array.size << std::endl;
    // dynamic_array.printDynArr();

    // // remove
    // dynamic_array.remove();

    // // print
    // std::cout << "avail: " << dynamic_array.avail << std::endl;
    // std::cout << "size: " << dynamic_array.size << std::endl;
    // dynamic_array.printDynArr();
}