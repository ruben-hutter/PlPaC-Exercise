#include "Set.h"
#include <iostream>

using namespace std;

int main ()
{
    cout << "creating set";
	Set testset;
    
    cout << "pop'ing set";
    testset.add(1.1, 2.2, "test0", 0);
    testset.add(2.2, 4.4, "test1", 1);
    testset.add(3.3, 6.6, "test2", 2);

    cout << "rint n sort";
    testset.print();

    testset.sort();

    cout << "test contains";
    cout << testset.contains(1);
    cout << testset.contains(5);

    cout << "test remove";
    testset.remove(1);

    testset.print();

    cout << "test size";
    cout << testset.size();
}
