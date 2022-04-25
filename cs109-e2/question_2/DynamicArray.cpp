# include <iostream>
using namespace std;

class DynamicArray
{
	int* array;
	int tail = 0;
	int bufferTail = 0;
	int size;
	int avail;

private:
	void trim()
	{
		avail *= 2;
        int *temp = new int[avail];
        copy(array, array + size, temp);
        delete [] array;
        array = temp;
	}

public:
	DynamicArray()
	{
			array = new int[10];
			avail = 10;
			size = 0;

	}

	~DynamicArray()
	{
		delete[] array;
	}

	int get(int index)
	{
		return array[index];
	}

	void set(int index, int value)
	{
		if (index < 0 || index > size){
			return;
		}
    	array[index] = value;
	}

	void add(int value)
	{
        if	(size == avail) {
            trim();
        }
        array[size] = value;
        size++;
	}

	void remove(int index)
	{
		if (index < 0 || index > size){
			return;
		}
        size--;
        for (int i = index; i < size; i++) {
            array[i] = array[i + 1];
        }
	}
};
