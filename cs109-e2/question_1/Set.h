//scheisse
#ifndef SET_H
#define SET_H
#include <string>
#include <algorithm>
#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class Set
{
public:
    // struct to store entries
	struct Entry
	{
		int uid;
		float firstFloat;
		float secondFloat;
		string entryString;
        bool operator< (const Entry &entry)
        {
            float entryNorm = sqrt(pow(entry.firstFloat, 2) + pow(entry.secondFloat, 2));
			float ownNorm = sqrt(pow(firstFloat, 2) + pow(secondFloat, 2));
			return entryNorm > ownNorm;
        }
	} entry;

	// adds element to list
	int add(float x, float y, string name, int id = -1);

	// removes the element with the specified id
	int remove(int id);

	// returns 1 if found, 0 if not found
	int contains(int id);

	// return number of elements in list
	unsigned int size();

	// sort elems by norm
	void sort(int sort_type = 0, bool reorganize = false);

	// print all entries to sdt::cout
	void print();

	void destroy();

private:
	list<Entry> entryList;
};

#endif
