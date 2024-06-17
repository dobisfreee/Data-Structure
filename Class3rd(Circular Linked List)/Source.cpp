#include <iostream>

using namespace std;

template <typename T>
class CircularLinkedList
{
private:
	int size;

	struct Node
	{
		T data;

		Node* next;
	};

	Node* head;

public:
	CircularLinkedList()
	{
		size = 0;
		head = nullptr;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			head->next = newNode;
			head = newNode;
		}
		size++;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;

			head->next = newNode;
		}
		size++;
	}

	void PopFront()
	{
		if (head = nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head->next;

			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				head->next = deleteNode->next;
			}
			delete deleteNode;
			size--;
		}

	}

	void PopBack()
	{
		if (head = nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == head->next)
			{
				head = nullptr;
			}
			else
			{
				Node* currentNode = head;
				Node* deleteNode = head;
				for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}
				currentNode->next = head->next;
				head = currentNode;
			}
			delete deleteNode;
			size--;
		}
	}

	void Show()
	{
		Node* currentNode = head->next;
		for (int i = 0; i < size; i++)
		{
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << "Size : " << size << endl;
	}


};


int main()
{
	CircularLinkedList<int> circularlinkedlist;
	circularlinkedlist.PushBack(10);
	circularlinkedlist.PushBack(20);
	circularlinkedlist.PushBack(30);
	circularlinkedlist.PopFront();
	circularlinkedlist.Show();


	return 0;
}