#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	Node* head;
	Node* tail;

public:
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

};

int main()
{
	DoublyLinkedList<int> doublylinkedlist;

	doublylinkedlist.PushFront(10);
	doublylinkedlist.PushFront(20);
	doublylinkedlist.PushFront(30);
	doublylinkedlist.Show();
	

	return 0;
}