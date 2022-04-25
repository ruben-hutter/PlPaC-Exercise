#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <cmath>
using namespace std;

class Set
{
	// struct to store entries
	struct Entry
	{
		int uid;
		float firstFloat;
		float secondFloat;
		string string;
	};

	list<Entry> entryList;

	// adds element to list
	int add(double x, double y, string name, int id = -1)
	{
		Entry entry = {id, x, y, name};
		list<Entry>::iterator it = entryList.begin();
		while (it != entryList.end())
		{
			if (it->uid == id)
			{
				return 0;
			}
		}
		entryList.push_front(entry);
		sort();
		return 1;
	}

	// removes the element with the specified id
	int remove(int id)
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
	int contains(int id)
	{
		for (Entry e : entryList)
		{
			if (e.uid == id)
			{
				return 1;
				{
				}
				return 0;
			}
		}
	}

	// return number of elements in list
	unsigned int size()
	{
		return entryList.size();
	}

	// sort elems by norm
	void sort(int sort_type = 0, bool reorganize = false)
	{
		std::sort(entryList.begin(), entryList.end(), [](const Entry &first, const Entry &second)
				  {
			float n1 = sqrt(first.firstFloat*first.firstFloat + first.secondFloat*first.secondFloat);
			float n2 = sqrt(second.firstFloat*second.firstFloat + second.secondFloat*second.secondFloat);
			return n1 < n2; });
	}

	// print all entries to sdt::cout
	void print()
	{
		for (Entry e : entryList)
		{
			std::cout << "(" << e.uid << ", " << e.firstFloat << ", " << e.secondFloat << ", " << e.string << "),";
		}
	}

	void destroy()
	{
	}
};
