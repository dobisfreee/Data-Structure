#include <iostream>

using namespace std;

#define SIZE 6

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;

        Node* next;
    };

    struct Bucket
    {
        int count;
        Node* head;
    };

    Bucket bucket[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            bucket[i].count = 0;
            bucket[i].head = nullptr;
        }
    }

    template <typename T>
    int HashFunction(T key)
    {
        int hashIndex = (int)key % SIZE;

        return hashIndex;
    }

    template<>
    int HashFunction(std::string.key)
    {
        int result = 0;

        for (const char& element : key)
        {
            result + = element;
        }

        unsigned int hashIndex = (int)result % SIZE;

        return hashIndex;
    }

    Node* CreateNode(KEY key, VALUE value)
    {
        Node* newNode = new Node();
        newNode->key = key;

        newNode->value = value;

        newNode->next = nullptr;

        return newNode;
    }

    void Insert(KEY key, VALUE value)
    {
        int hashIndex = HashFunction(key);

        Node* newNode = CreateNode(key, value);

        if (bucket[hashIndex].head == nullptr)
        {
            bucket[hashIndex]->head = newNode;
        }
        else
        {
            newNode->next = bucket[hashIndex]->head
                bucket[hashIndex]->head = newNode;
        }

        bucket[hashIndex]->count++;
    }

    void Remove(KEY key)
    {
        int hashIndex = HashFunction(key);

        Node* currentNode = bucket[hashIndex].head;

        if (currentNode == nullptr)
        {
            cout << "Key Not Found" << endl;
            return;
        }
        else if (currentNode != nullptr)
        {

            Node* previousNode = nullptr;

            while (currentNode->key != key)
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }

            if (currentNode == bucket[hashIndex].head)
            {
                bucket[hashIndex].head = currentNode->next;
            }
            else
            {
                previousNode->next = currentNode->next;
            }

            delete currentNode;

            bucket[hashIndex].count--;

        }
        else
        {
            cout << "Key Not Found" << endl;
        }


    }

    void Show()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* currentNode = bucket[i].head;

            while (currentNode != nullptr)
            {
                cout << "[" << i << "]" << "KEY : " << currentNode->key << " VALUE :" << currentNode->value << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node* deleteNode = bucket[i].head;
            Node* nextNode = bucket[i].head;

            if (bucket[i].head == nullptr)
            {
                continue;
            }
            else
            {
                while (nextNode != nullptr)
                {
                    nextNode = deleteNode->next;
                    delete deleteNode;
                    deleteNode = nextNode;
                }
            }
        }
    }

};

int main()
{
    HashTable<std::string, std::string>  hashTable;

    hashTable.Insert("Sword", "100");
    hashTable.Insert("Diamond", "999");

    hashTable.Remove("Branch");







    return 0;
}