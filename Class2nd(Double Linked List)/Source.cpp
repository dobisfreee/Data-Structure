#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList
{
private:
	int size;

	struct Node; // prototype 선언만 하고 구현은 안하는

	Node* head;
	Node* tail;

public:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	DoublyLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void Show()
	{
		Node* currentNode = head;
		while (currentNode != nullptr)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << "Size : " << size << endl;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (size == 0)
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;

		}
		size++;
	}

	void PopBack()
	{
		if (tail == nullptr)
		{
			cout << "Linked List is empty" << endl;
		}
		else
		{
			Node* deleteNode;

			deleteNode = tail;
			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;

				delete deleteNode;
			}
			else
			{
				tail->previous->next = nullptr;

				tail = tail->previous;

				delete deleteNode;

			}

			size--;
		}
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		newNode->previous = nullptr;


		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			head->previous = newNode;
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void PopFront()
	{
		if (size == 0)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (size == 1)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				deleteNode->next->previous = nullptr;
				head = head->next;
			}
			delete deleteNode;
			size--;
		}
	}

	int& Size()
	{
		return size;
	}

	Node* Begin()
	{
		return head;
	}

	void Insert(Node* position, T data)
	{
		if (head == nullptr)
		{
			PushBack(data);
		}
		else
		{
			Node* previousNode = position;
			Node* nextNode = position->next;

			if (previousNode->previous == nullptr)
			{
				PushFront(data);
			}
			else if (nextNode == nullptr)
			{
				PushBack(data);
			}
			else
			{
				Node* newNode = new Node;

				newNode->data = data;

				newNode->previous = previousNode;
				newNode->next = nextNode;

				previousNode->next = newNode;
				nextNode->previous = newNode;

				size++;
			}

		}

	}

	~DoublyLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

};

int main()
{
	DoublyLinkedList<int> doublylinkedlist;

	doublylinkedlist.PushFront(10);
	doublylinkedlist.PushFront(20);
	doublylinkedlist.PushFront(30);

	doublylinkedlist.Insert(doublylinkedlist.Begin()->next->next, 99);  // 30 20 10 99 

	doublylinkedlist.Show();


	// cout << "Double Linked List의 주소값 : " << doublylinkedlist.Begin()->next << endl; 


	return 0;
}