#include <Set.h>
#include <string>
#include <iostream>

using namespace std;

int main ()
{
	Set testset;
    
    testset.add(1.1, 2.2, "test0", 0);
    testset.add(2.2, 4.4, "test1", 1);
    testset.add(3.3, 6.6, "test2", 2);

    testset.print();

    testset.sort();

    cout << testset.contains(1);
    cout << testset.contains(5);

    testset.remove(1);

    testset.print();

    cout << testset.size();
}
