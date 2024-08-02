#include <iostream>

using namespace std;

#define SIZE 26

class Trie  // 뿌리 내릴 때마다 Trie 객체 자체를 생성 -> 메모리 많이 사용 
{
private:
	bool final; // 단어의 끝 문자 즉, NULL문자를 만나면 true  

	Trie* alphabet[SIZE];    

public:
	Trie()
	{
		final = false;
		
		for (int i = 0; i < SIZE; i++)
		{
			alphabet[i] = nullptr;
		}
	}
};
int main()
{

	return 0;
}