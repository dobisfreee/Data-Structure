#include <iostream>

using namespace std;

template<typename T>
class SingleLInkedList
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
    SingleLInkedList()
    {
        size = 0;
        head = nullptr;
    }

    void PushFront(T data)
    {
        if (head == nullptr)
        {
            head = new Node;

            head->data = data;
            head->next = nullptr;
        }
        else
        {
            Node* newNode = new Node;
            newNode->next = head;
            newNode->data = data;

            head = newNode;
        }

        size++;
    }
    void Show()
    {
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;

        }

    }
};


int main()
{
    SingleLInkedList<int> singleLinkedList;
    singleLinkedList.PushFront(10);
    singleLinkedList.PushFront(20);
    singleLinkedList.Show();

    return 0;
}


