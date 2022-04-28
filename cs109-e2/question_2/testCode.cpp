#include "DynamicArray.h"

int main()
{
    LinkedList ll;

    int* operand;
    int value = 4;
    operand = &value;

    LinkedList::Node node1;
    BufferedChange buff_change(operand, BufferedChange::ADD, 4);
    node1.bufferedChange = &buff_change;

    ll.appendTail(&node1);
    ll.print();
}