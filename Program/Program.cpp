#include <iostream>

#define SIZE 6

using namespace std;

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
		Node* head;

		int count;
	};

	Bucket bucket[SIZE];

public:
	HashTable()
	{
		for (int i = 0; i < SIZE; i++)
		{
			bucket[i],count = 0;
			bucket[i].head = nullptr;
		}
	}

};



int main()
{

	return 0;
}