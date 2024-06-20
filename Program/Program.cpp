#include <iostream>

using namespace std;

class String
{
private:
	char * container;

	int size;

public:
	String()
	{
		size = 0;
		container = nullptr;
	}

	void operator = (const char * content)
	{
		int arraySize = strlen(content) + 1; // strlen()은 NULL을 제외한 문자열의 길이이기
		size = strlen(content);				 // 때문에 +1을 해주어야 한다. 

		if (container == nullptr)
		{
			container = new char [arraySize];

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

	char & operator [] (int index)
	{
		return container[index];
	}

	int& Size()
	{	
		return size;
	}

	int Compare(const char * content)
	{	
		int arraySize = 0;

		if (strlen(container) > strlen(content))
		{
			arraySize = strlen(container);
		}
		else if (strlen(container) < strlen(content))
		{
			arraySize = strlen(content);
		}
		else
		{
			arraySize = strlen(container);
		}

		for (int i = 0; i < arraySize; i++)
		{
			if (container[i] > content[i])
			{
				return 1;
			}
			else if (container[i] < content[i])
			{
				return -1;
			}
		}
		return 0;
		
	}

};

int main()
{
	String string; 

	string = "Ana";

	int flag = string.Compare("Tracer");

	cout << flag << endl;

	


	return 0;
}