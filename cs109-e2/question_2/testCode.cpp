#include "DynamicArray.h"

int main()
{
    DynamicArray dynamic_array(-1);

    // // add first 40 entries
    // for (int i = 0; i < 40; i++)
    // {
    //     dynamic_array.add(i);
    // }

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


    // add
    dynamic_array.add(1);
    dynamic_array.add(2);
    dynamic_array.add(1);
    dynamic_array.add(2);
    dynamic_array.add(1);
    dynamic_array.add(2);

    // print
    std::cout << "avail: " << dynamic_array.avail << std::endl;
    std::cout << "size: " << dynamic_array.size << std::endl;
    dynamic_array.printDynArr();

    // make grow()
    dynamic_array.add(1);
    dynamic_array.add(2);
    dynamic_array.add(2);

    // print
    std::cout << "avail: " << dynamic_array.avail << std::endl;
    std::cout << "size: " << dynamic_array.size << std::endl;
    dynamic_array.printDynArr();


    // remove
    dynamic_array.remove();
    dynamic_array.remove();
    dynamic_array.remove();
    dynamic_array.remove();
    dynamic_array.remove();
    dynamic_array.remove();

    // print
    std::cout << "avail: " << dynamic_array.avail << std::endl;
    std::cout << "size: " << dynamic_array.size << std::endl;
    dynamic_array.printDynArr();

    // // remove
    // dynamic_array.remove();

    // // print
    // std::cout << "avail: " << dynamic_array.avail << std::endl;
    // std::cout << "size: " << dynamic_array.size << std::endl;
    // dynamic_array.printDynArr();
}