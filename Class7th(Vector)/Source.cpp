#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:
	int size;
	int capacity;
	T* container;
public:

	Vector()
	{
		size = 0;
		capacity = 0;
		container = nullptr;
	}

	void Resize(int newSize)
	{
		capacity = newSize;

		T* newContainer = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			newContainer[i] = NULL;
		}

		for (int j = 0; j < size; j++)
		{
			newContainer[j] = container[j];
		}
		if (container != nullptr)
		{
			delete[] container;
		}
		container = newContainer;

	}

	T& operator [] (const int& index)
	{
		return container[index];
	}

	void PushBack(T data)
	{
		if (capacity <= 0)
		{
			Resize(1);
		}
		else if (size >= capacity)
		{
			Resize(capacity * 2);
		}

		container[size++] = data;

	}

	void PopBack()
	{
		if (size <= 0)
		{
			cout << "Vector is Empty" << endl;
		}
		else
		{
			container[--size] = NULL;
		}
	}

	void Reserve(int newSize)
	{
		if (newSize < capacity)
		{
			return;
		}
		Resize(newSize);
	}

	~Vector()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

	int& Size()
	{
		return size;
	}

};

int main()
{

	Vector<int> vector;

	vector.PushBack(10);
	vector.PushBack(20);
	vector.PushBack(30);

	for (int i = 0; i < vector.Size(); i++)
	{
		cout << vector[i] << endl;
	}
	return 0;
}