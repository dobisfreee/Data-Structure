#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>
class CircularQueue
{
private:

	int size;
	int rear;
	int front;

	T container[SIZE];

public:

	CircularQueue()
	{
		size = 0;
		rear = SIZE - 1;
		front = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void Push(T data)
	{
		if ((rear + 1) % SIZE == front)
		{
			cout << "CircularQueue Overflow" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;
			container[rear] = data;
			size++;
		}
	}

	void Pop()
	{
		if (Empty())
		{
			cout << "CircularQueue is Empty" << endl;
		}
		else
		{
			front = (front + 1) % SIZE;
			container[front] = NULL;
			size--;
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

	T& Front()
	{
		if (Empty())
		{
			exit(1);
		}
		else
		{
			return container[(front + 1) % SIZE];
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
			return container[rear];
		}
	}

	int& Size()
	{
		return size;
	}



};

using namespace std;

int main()
{
	CircularQueue<char> circularqueue;

	circularqueue.Push('A');
	circularqueue.Push('B');
	circularqueue.Push('C');
	circularqueue.Push('D');



	while (circularqueue.Empty() == false)
	{
		cout << circularqueue.Front() << endl;
		circularqueue.Pop();
	}

	circularqueue.Push('E');
	circularqueue.Push('F');

	while (circularqueue.Empty() == false)
	{
		cout << circularqueue.Front() << endl;
		circularqueue.Pop();
	}


	return 0;
}

