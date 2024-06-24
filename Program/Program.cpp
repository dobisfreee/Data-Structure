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

         for (const char & element : key)
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

       Node * newNode = CreateNode(key, value);

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

};

int main()
{
    HashTable<std::string, std::string>    hashTable;

    cout << hashTable.HashFunction("Kim");


    return 0;
}