#include <iostream>

using namespace std;

#define SIZE 8

template <typename T>
class Heap
{
private:
	int index;

	T container[SIZE];

public:
	Heap()
	{
		index = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}
	void Insert(T data)
	{
		if (index >= SIZE)
		{
			cout << "Heap Overflow" << endl;
		}
		else 
		{
			container[++index] = data;

			int child = index;
			int parent = child / 2;

			int temp = 0;

			while (child > 1)
			{
				if (container[parent] < container[child])
				{
					std::swap(container[parent], container[child]);
				}

				child = parent;
				parent = child / 2;

			}
		}
	}

	T Remove()
	{
		if (index <= 0)
		{
			cout << "Heap is Empty" << endl;
			exit (1);
		}
		
		
			T result = container[1];
	
			container[1] = container[index];

			container[index] = NULL;

			index--;

			int parent = 1;

			int left = parent * 2;

			int right = parent * 2 + 1;

			while (container[parent] < container[right] || container[parent] < container[left])
			{
				if (container[parent] < container[right])
				{
					std::swap(container[parent], container[right])

						right = parent;
					
						
				}
				else if (container[parent] < container[left])
				{
					std::swap(container[parent], container[left])

						left = parent;
						parent = left / 2;
				}

			}

	}

	void Show()
	{
		for (int i = 1; i <= index; i++)
		{
			cout << container[i] << " ";
		}
	}
};


int main()
{
	Heap<int> heap;

	heap.Insert(6);
	heap.Insert(7);
	heap.Insert(2);
	heap.Insert(10);

	heap.Show();

	return 0;
}