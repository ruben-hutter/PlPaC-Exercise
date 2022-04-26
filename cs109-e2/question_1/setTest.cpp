#include "Set.h"
#include <iostream>

using namespace std;

int main ()
{
    cout << "creating set" << endl;
	Set testset;

    cout << "populating set" << endl;
    testset.add(1.1, 2.2, "test0", 0);
    testset.add(2.2, 4.4, "test1", 1);
    testset.add(3.3, 6.6, "test2", 2);

    cout << "print & sort" << endl;
    testset.print();

    testset.sort();

    cout << "test contains" << endl;
    cout << testset.contains(0);
    cout << testset.contains(5);

    cout << "test remove" << endl;
    testset.remove(0);

    testset.print();

    cout << "test size" << endl;
    cout << testset.size() << endl;
}
