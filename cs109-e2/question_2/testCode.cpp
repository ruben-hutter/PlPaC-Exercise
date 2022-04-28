#include "DynamicArray.h"

int main()
{
    LinkedList ll;

    int value0 = 8;
    int value1 = 1;
    int value2 = 3;
    int* operand0 = &value0;
    int* operand1 = &value1;
    int* operand2 = &value2;

    // node0
    LinkedList::Node node0;
    BufferedChange buff_change0(operand0, BufferedChange::ADD, 2);
    node0.bufferedChange = &buff_change0;

    // node1
    LinkedList::Node node1;
    BufferedChange buff_change1(operand0, BufferedChange::MULT, 2);
    node1.bufferedChange = &buff_change1;

    // node2
    LinkedList::Node node2;
    BufferedChange buff_change2(operand1, BufferedChange::ADD, 4);
    node2.bufferedChange = &buff_change2;

    // node3
    LinkedList::Node node3;
    BufferedChange buff_change3(operand2, BufferedChange::ADD, 4);
    node3.bufferedChange = &buff_change3;

    ll.appendTail(&node0);
    ll.append(&node1, &node0);
    ll.appendTail(&node2);
    ll.appendTail(&node3);

    ll.print();

    int value_1 = ll.getValueOf(&node0);
    std::cout << "value of 1: " << value_1 << std::endl;
}