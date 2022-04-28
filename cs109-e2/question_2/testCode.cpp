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
    LinkedList::Node* node0 = new LinkedList::Node;
    node0->bufferedChange = new BufferedChange(operand0, BufferedChange::ADD, 2);

    // node1
    LinkedList::Node* node1 = new LinkedList::Node;
    node1->bufferedChange = new BufferedChange(operand0, BufferedChange::MULT, 2);

    // node2
    LinkedList::Node* node2 = new LinkedList::Node;
    node2->bufferedChange = new BufferedChange(operand1, BufferedChange::ADD, 2);

    // node3
    LinkedList::Node* node3 = new LinkedList::Node;
    node3->bufferedChange = new BufferedChange(operand2, BufferedChange::ADD, 2);

    ll.appendTail(node0);
    ll.append(node1, node0);
    ll.appendTail(node2);
    ll.appendTail(node3);

    ll.print();
    ll.execute();
    ll.print();
}