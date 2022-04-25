# include <string>
# ifndef Set
# define Set


class Set
{
struct Entry {
	int uid;
	float firstFloat;
	float secondFloat;
	string string;



}

public:
	int add(double x, double y, string name, int id = -1);
	int remove(int id);
	int contains(int id);
	unsigned int size();
	void sort(int sort_type = 0, bool reorganize = false);
	void print();
	void destroy();
}

# endif
