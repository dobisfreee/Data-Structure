#include <iostream>

#define SIZE 5

using namespace std;

template <typename T>
class LinearQueue
{
private:
	int size;
	int rear;
	int front;

	T container[SIZE];

public:

	LinearQueue()
	{
		size = 0;
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	bool Empty()
	{
		if (rear == front)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "Queue Overflow" << endl;
		}
		else
		{
			container[rear++] = data;
			size++;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "Linear Queu is Empty" << endl;
		}
		else
		{
			container[front++] = NULL;
			size--;
		}
	}

	T& Front()
	{
		if (Empty())
		{
			exit(1);
		}
		else
		{
			return container[front];
		}

	}

	T& Back()
	{
		if (Empty())
		{
			exit(1);
		}
		else
		{
			return container[rear - 1];
		}
	}

	int& Size()
	{
		return size;
	}

};

int main()
{
	LinearQueue<int> linearqueue;

	linearqueue.Push(10);
	linearqueue.Push(20);
	linearqueue.Push(30);
	linearqueue.Push(40);
	linearqueue.Push(50);


	cout << "가장 뒤에 있는 값 : " << linearqueue.Back() << endl;

	while (linearqueue.Empty() == false)
	{
		cout << linearqueue.Front() << endl;
		linearqueue.Pop();
	}





	return 0;
}