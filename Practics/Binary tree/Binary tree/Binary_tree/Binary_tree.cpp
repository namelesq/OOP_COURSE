#include <iostream>
#include <Windows.h>
struct Node
{
	Node* left;
	Node* right;
	int data;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

Node* InsertNode(Node* root, int data)
{
	if (root == nullptr) { return CreateNode(data); }

	if (data < root->data) { root->left = InsertNode(root->left, data); }
	else if (data > root->data) { root->right = InsertNode(root->right, data); }
	
	return root;

}

void InorderWalk(Node* root)
{
	if (root != nullptr) { InorderWalk(root->left); std::cout << root->data << " "; InorderWalk(root->right); } 
	
}

Node* SearchNode(Node* root, int val)
{
	if (root == nullptr || root->data == val) { return root; }

	if (root->data < val) { return SearchNode(root->right, val); }

	return SearchNode(root->left, val);
}

Node* MinValueNode(Node* node)
{
	Node* current = node;
	while (current && current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

Node* DeleteNode(Node* root, int data)
{
	if (root == nullptr) { return root; }

	if (data < root->data) { root->left = DeleteNode(root->left, data); }
	else if (data > root->data) { root->right = DeleteNode(root->right, data); }
	else
	{
		if (root->left == nullptr) { Node* tmp = root->right; delete  root; return tmp; }
		else if (root->right == nullptr) { Node* tmp = root->left; delete root; return tmp; }

		Node* tmp = MinValueNode(root->right);
		root->data = tmp->data;
		root->right = DeleteNode(root->right, tmp->data);
	}
	 
	return root;

}	

int main()
{
	Node* node = nullptr;
	node = InsertNode(node, 50);
	node = InsertNode(node, 30);
	node = InsertNode(node, 20);
	node = InsertNode(node, 40);
	node = InsertNode(node, 70);
	node = InsertNode(node, 80);
	node = InsertNode(node, 90);
	
	InorderWalk(node);
	std::cout<<std::endl;

	DeleteNode(node, 50);
	InorderWalk(node);
	std::cout << std::endl;
	
	return 0;
}