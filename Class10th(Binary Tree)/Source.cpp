#include <iostream>

using namespace std;

struct Node
{
	int data;

	Node* left;
	Node* right;
};

Node* CreateNode(int data, Node* left, Node* right)
{
	Node* newNode = new Node;

	newNode->data = data;

	newNode->left = left;

	newNode->right = right;

	return newNode;
}

void Preorder(Node* root)
{
	if (root != nullptr) // 재귀함수가 끝나는 조건 
	{
		cout << root->data << " ";

		Preorder(root->left);
		Preorder(root->right);
	}

		// 1. node1 출력
		// 2. node1의 왼쪽 탐색 
		// 3. node2 출력
		// 4. node2의 왼쪽 탐색
		// 5. node4 출력
		// 6. node4의 왼쪽 탐색 
		// 7. null을 만나 재귀 종료
		// 8. node4로 다시 돌아온 후 왼쪽 탐색과 출력을 이미 실행했기 때문에 node4의 오른쪽 탐색
		// 9. null을 만나 재귀 종료
		// 10. node4으로 돌아왔으나 모든 것을 실행했기 때문에 node2로 돌아옴
		// 11. node2는 출력과 왼쪽 탐색을 마쳤기 때문에 오른쪽 탐색 시작
		// 12. node5 출력 후 node5의 왼쪽 탐색
		// 13. null을 만나 재귀 종료 
		// 14. node5으로 돌아온 후, 출력과 왼쪽 탐색을 모두 마쳤기 때문에 node5의 오른쪽 탐색
		// 15. null을 만나 node5으로 돌아갔으나 모든 코드를 실행했기 때문에 node2으로 돌아감
		// 16. node2 또한 모든 코드를 실행했기 때문에 node1으로 돌아감
		// 17. node1의 경우, 출력과 왼쪽 탐색을 마쳤기 때문에 오른쪽 탐색을 시작
		// 18. 위의 과정을 반복 

}


void Inorder(Node* root)
{
	if (root != nullptr)
	{
		Inorder(root->left);
		cout << root->data << " ";
		Inorder(root->right);
	}
}

void Postorder(Node* root)
{
	if (root != nullptr)
	{
		Postorder(root->left);
		Postorder(root->right);
		cout << root->data << " ";
	}
}


int main()
{
	Node* node7 = CreateNode(7, nullptr, nullptr);
	Node* node6 = CreateNode(6, nullptr, nullptr);
	Node* node5 = CreateNode(5, nullptr, nullptr);
	Node* node4 = CreateNode(4, nullptr, nullptr);

	Node* node3 = CreateNode(3, node6, node7);
	Node* node2 = CreateNode(2, node4, node5);
	Node* node1 = CreateNode(1, node2, node3);

	// Preorder(node1);

	// Inorder(node1);

	// Postorder(node1);
	return 0;
}