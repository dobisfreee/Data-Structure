#include <iostream>

using namespace std;

class String
{
private:
	char* container;

	int size;

public:
	String()
	{
		size = 0;
		container = nullptr;
	}

	void operator = (const char* content)
	{
		int arraySize = strlen(content) + 1; // strlen()은 NULL을 제외한 문자열의 길이이기
		size = strlen(content);				 // 때문에 +1을 해주어야 한다. 

		if (container == nullptr)
		{
			container = new char[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				container[i] = content[i];
			}
		}
		else
		{
			char* newContainer = new char[arraySize];

			for (int j = 0; j < arraySize; j++)
			{
				newContainer[j] = content[j];
			}

			delete[] container;

			container = newContainer;
		}


	}

	char& operator [] (int index)
	{
		return container[index];
	}

	int& Size()
	{
		return size;
	}

	int Compare(const char* content)
	{
		int count = 0;

		for (int i = 0; i < strlen(content); i++)
		{
			if (container[i] != content[i])
			{
				break;
			}
			else
			{
				count++;
			}
		}

		if (strlen(content) == count)
		{
			return 0;
		}

		int classString = 0;
		int otherString = 0;

		for (int i = 0; i < strlen(container); i++)
		{
			classString += container[i];
		}
		for (int i = 0; i < strlen(content); i++)
		{
			otherString += content[i];
		}
		if (classString > otherString)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	};

	void Append(const char* content)
	{
		if (container == nullptr)
		{
			cout << "Container is Empty" << endl;
		}
		else
		{
			int newSize = strlen(container) + strlen(content);
			// NULL 문자 포함 -> +1 불필요
			char* newcontainer = new char[newSize];

			for (int i = 0; i < strlen(container); i++)
			{
				newcontainer[i] = container[i];

			}

			for (int j = 0; j < strlen(content); j++)
			{
				newcontainer[j + strlen(container)] = content[j];
			}

			size = newSize;

			delete[] container;

			container = newcontainer;

		}
	}
	~String()
	{
		if (container != nullptr)
		{
			delete[] container;
		}
	}

};


int main()
{
	String string;

	string = "League";

	string.Append("of");



	for (int i = 0; i < string.Size(); i++)
	{
		cout << string[i];
	}
	return 0;
}