#include <iostream>

using namespace std;
template <typename T>
class BinarySearchTree
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
	};

	Node* root;

public:

	BinarySearchTree()
	{
		root = nullptr;
	}

	Node* Root()
	{
		return root;
	}

	Node* CreateNode(T data)
	{
		Node* newNode = new Node();

		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;

		return newNode;
	}

	void Insert(T data) // 작으면 왼쪽, 크면 오른쪽
	{
		if (root == nullptr)
		{
			root = CreateNode(data);
		}
		else
		{
			Node* currentNode = root;
	
			while (currentNode != nullptr)
			{
				if (currentNode->data < data)
				{
				if (currentNode->right == nullptr)
				{
					currentNode->right = CreateNode(data);
						break; 
				}
				else
				{
					currentNode = currentNode->right;
				}
	 			}
 			else if (currentNode->data > data)
 			{
 				if (currentNode->left == nullptr)
 				{
 					currentNode->left = CreateNode(data);
 					break;
 				}
					else
					{
	 					currentNode = currentNode->left;
	 				}
	 			}
	 			else
	 			{
	 				return;
	 			}
			}
	 	}
	 }

	// void Insert(T data, Node * root)
	// {
	// 	if (root == nullptr)
	// 	{
	// 		root = CreateNode(data);
	// 	}
	// 	else
	// 	{
	// 		Node* currentNode = root;
	// 
	// 		if (currentNode != nullptr)
	// 		{
	// 			if (currentNode->data > data)
	// 			{
	// 				if (currentNode->left == nullptr)
	// 				{
	// 					currentNode->left = CreateNode(data);
	// 				}
	// 				else
	// 				{
	// 					Insert(data, root->left);
	// 				}
	// 			}
	// 			else if(currentNode->data < data)
	// 			{
	// 				if (currentNode->right == nullptr)
	// 				{
	// 					currentNode->right = CreateNode(data);
	// 				}
	// 				else
	// 				{
	// 					Insert(data, root->left);
	// 				}
	// 			}
	// 			else
	// 			{
	// 				return;
	// 			}
	// 		}
	// 	}
	// }

	bool Find(T data)
	{
		Node* currentNode = root; 
		if (root == nullptr)
		{
		
			return false;
		}
		else
		{
			while (currentNode != nullptr)
			{
				if (currentNode->data < data)
				{
					currentNode = currentNode->right;
				}
				else if (currentNode->data > data)
				{
					currentNode = currentNode->left;
				}
				else 
				{
					
					return true;
				}
			}
			
			return false;
		}
	}
	void Inorder(Node * root)
	{
		if (root != nullptr)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}

	void Destroy(Node * root)
	{
		if (root != nullptr)
		{
			Destroy(root->left);
			Destroy(root->right);
			delete root;
		}
	}

	~BinarySearchTree()
	{
		Destroy(root);
	}
};
int main()
{

	BinarySearchTree <int> binarySearchTree;
	
	binarySearchTree.Insert(10);
	binarySearchTree.Insert(7);
	binarySearchTree.Insert(15);
	binarySearchTree.Insert(5);

	cout << binarySearchTree.Find(2) << endl;

	binarySearchTree.Inorder(binarySearchTree.Root());

	return 0;
}