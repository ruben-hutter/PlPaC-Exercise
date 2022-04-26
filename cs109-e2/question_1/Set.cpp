#include "Set.h"
using namespace std;

// adds element to list
int Set::add(double x, double y, string name, int id)
{
	Entry entry = {id, x, y, name};
	list<Entry>::iterator it = entryList.begin();
	while (it != entryList.end())
	{
		if (it->uid == id)
		{
			return 0;
		}
		++it; // was missing?
	}
	entryList.push_back(entry);
	//sort();
	return 1;
}

// removes the element with the specified id
int Set::remove(int id)
{
	list<Entry>::iterator it = entryList.begin();
	while (it != entryList.end())
	{
		if (it->uid == id)
		{
			entryList.erase(it);
			sort();
			return 1;
		}
		++it;
	}
	return 0;
}

// returns 1 if found, 0 if not found
int Set::contains(int id)
{
	for (Entry e : entryList)
	{
		if (e.uid == id)
		{
			return 1;
		}
	}
	return 0;
}

// return number of elements in list
unsigned int Set::size()
{
	return entryList.size();
}

// sort elems by norm
void Set::sort(int sort_type, bool reorganize)
{
	entryList.sort();
}

// print all entries to sdt::cout
void Set::print()
{
	std::cout << "The set contains the following elements:" << endl;
	for (Entry e : entryList)
	{
		std::cout << "(" << e.uid << ", " << e.firstFloat << ", " << e.secondFloat << ", " << e.entryString << "),";
	}
}

void Set::destroy()
{
	// TODO i guess...
}
