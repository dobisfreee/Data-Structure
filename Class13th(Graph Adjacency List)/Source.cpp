#include <iostream>

using namespace std;

#define SIZE 10;

template <typename T>
class AdjacencyList
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr) // 구조체 생성자
		{
			this->data = data;
			next = link;
		}
	};

	int size; // 정점의 개수
	T vertex[SIZE]; // 정점의 집합
	Node* list[SIZE]; // 인접 리스트

public:

	AdjacencyList()
	{
		size = 0;

		for (int i = 0; i < SIZE; i++)
		{
			vertex[i] = NULL;
			list[i] = NULL;
		}
	}

	void Insert(T data)
	{
		if (size >= SIZE)
		{
			cout << "AdjacencyList Overflow" << endl;
		}

		vertex[size++] = data;
	}

	void Connect(int u, int v)
	{
		if (size <= 0)
		{
			cout << "AdjacencyList is Empty" << endl;

		}
		else if (u >= size || v >= size)
		{
			cout << "Index Out of Range" << endl;
		}
		else
		{
			list[u] = new Node(vertex[v], list[u]);
			list[v] = new Node(vertex[u], list[v]);

		}

	}

	void Show()
	{
		if (size <= 0)
		{
			cout << "AdjacencyList is Empty" << endl;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << vertex[i] << " : ";

				Node* currentNode = list[i];

				while (currentNode != nullptr)
				{
					cout << currentNode->data << " ";
					currentNode = currentNode->next;
				}

				cout << endl;
			}

		}
	}
	~AdjacencyList()
	{
		if (size <= 0)
		{
			cout << "AdjacencyList is Empty" << endl;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (list[i] != nullptr)
				{
					delete[] list[i];
				}
			}
		}
	}
};

int main()
{
#pragma region  인접 리스트
	// 그래프의 각 정점에 인접한 정점들을 연결 리스트로 
	// 표현하는 방법입니다. 

	// 장점
	// 그래프의 모든 간선의 수를 o(V + E)로 표현할 수 있습니다.

	// 단점
	// 두 정점을 연결하는 간선을 조회하거나 정점의 차수를 알기 
	// 위해서 정점의 인접 리스트를 모두 탐색해야 하므로, 
	// 정점의 차수만큼의 시간이 필요합니다. 

	AdjacencyList <char> adjacencyList;

	adjacencyList.Insert('A');
	adjacencyList.Insert('B');
	adjacencyList.Insert('C');
	adjacencyList.Insert('D');

	adjacencyList.Connect(0, 1);
	adjacencyList.Connect(0, 2);
	adjacencyList.Connect(2, 3);

	adjacencyList.~AdjacencyList();
	adjacencyList.Show();
#pragma endregion

	return 0;
}