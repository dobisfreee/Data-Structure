#include <iostream>

#define SIZE 10

using namespace std;

template <typename T>
class Stack
{
private:
	int top;

	T container[SIZE];


public:
	Stack()
	{
		top = -1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = 0;
		}

	}
	int& Size()
	{	
		return top++;
	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(T data)
	{
		if (top >= SIZE-1)
		{
			cout << "Stack Overflow" << endl;
		}
		else
		{	
			container[++top] = data; 
		}
	}
	void Pop()
	{
		if (Empty())
		{
			cout << "Stack is Empty" << endl;
		}
		else
		{
			top --;
		}
	}
	T& Top()
	{
		return container[top];
	}
	
};

bool CheckBracket(std::string content)
{	
	if (content.length() <= 0)
	{
		return false;
	}
	else 
	{
		Stack<char> stack;
		for (int i = 0; i < content.length() / 2; i++)
		{
			stack.Push(content[i]);
		}
		for (int j = content.length() / 2; j < content.length(); j++)
		{
			if (stack.Top() == content[j])
			{
				stack.Pop();
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	

}

int main()
{
	CheckBracket("");

	return 0;
}
