#ifndef SET_H
#define SET_H

class Set
{
public:
    // struct to store entries
	struct Entry
	{
		int uid;
		float firstFloat;
		float secondFloat;
		string string;
	} entry;

	// adds element to list
	int add(double x, double y, string name, int id = -1);

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