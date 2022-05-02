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
    std::cout << "> Initial array with 40 elem" << std::endl;
    dynamic_array.printDynArr();

    // add 5 elem
    for (int i = 0; i < 5; i++)
    {
        dynamic_array.add(i);
    }
    // print
    std::cout << "> Added 5 elem:" << std::endl;
    dynamic_array.printDynArr();

    // remove 5 elem
    for (int i = 0; i < 5; i++)
    {
        dynamic_array.remove();
    }
    // print
    std::cout << "> Removed 5 elem:" << std::endl;
    dynamic_array.printDynArr();

    // add 50 elem
    for (int i = 0; i < 50; i++)
    {
        dynamic_array.add(i);
    }
    // print
    std::cout << "> Added 50 elem:" << std::endl;
    dynamic_array.printDynArr();

    // remove 50 elem
    for (int i = 0; i < 50; i++)
    {
        dynamic_array.remove();
    }
    // print
    std::cout << "> Removed 50 elem:" << std::endl;
    dynamic_array.printDynArr();

    // test get() first time
    std::cout << "> Before set elem39: " << dynamic_array.get(39) << std::endl;
    // test set() first time
    dynamic_array.set(39, BufferedChange::ADD, 1);
    std::cout << "> Buffered elem39 + 1..." << std::endl;
    // test get() second time
    std::cout << "> After set elem39: " << dynamic_array.get(39) << std::endl;
    // test set() second time
    dynamic_array.set(39, BufferedChange::DIV, 2);
    std::cout << "> Buffered another change to elem39..." << std::endl;

    // print every data structure
    std::cout << "> Data structures after adding 2 modification to same element..." << std::endl;
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // test trim()
    dynamic_array.trim();
    std::cout << "> Trimming the buffer, executing changes..." << std::endl;

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // buffer second elem
    dynamic_array.set(39, BufferedChange::ADD, 10);
    std::cout << "> Added last elem to buffer..." << std::endl;

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // remove element that is in buffer
    dynamic_array.remove();
    std::cout << "> Removed buffered element..." << std::endl;

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // trim without elements buffered
    dynamic_array.trim();

    // adding some changes to buffer, to be overwritten
    dynamic_array.set(4, BufferedChange::MULT, 2);
    dynamic_array.set(4, BufferedChange::MULT, 2);
    dynamic_array.set(4, BufferedChange::MULT, 2);

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();
    std::cout << "> Updated value of elem4: " << dynamic_array.get(4) << std::endl;

    // overwrite changes to elem 4
    dynamic_array.overwrite(4, BufferedChange::ADD, 100);
    std::cout << "> After overwriting buffered changes of elem 4" << std::endl;

    // print every data structure
    dynamic_array.printDynArr();
    dynamic_array.buffer.printBuffer();
    dynamic_array.printAccess();

    // show updated value of elem 4
    std::cout << "> Updated value of elem4 after overwriting buffer: " << dynamic_array.get(4) << std::endl;
}