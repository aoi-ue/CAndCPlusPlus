#include <iostream>

using namespace std;

struct Node
{
	int value;
	struct Node *left, *right;
	int height;
};

Node *newNode(int item)
{
	Node *temp = new Node;
	temp->value = item;
	temp->left = temp->right = NULL;
	return temp;
}

int height(Node *node)
{
	if (node == NULL)
		return -1;
	int leftH = height(node->left);
	int rightH = height(node->right);

	if (leftH > rightH)
	{
		return leftH + 1;
	}
	else
	{
		return rightH + 1;
	}
}

void rotateRight(Node *root)
{
	Node *temp = root;
	root = root->left;
	temp->left = root->right;
	root->right = temp;
}

void rotateLeft(Node *root)
{
	Node *temp = root;
	root = root->right;
	temp->right = root->left;
	root->left = temp;
}

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	}
}
/* Practice Two - AVL Tree Insert */
Node *insert(Node *node, int value)
{
	if (node == NULL)
		return newNode(value);
	if (value < node->value)
		node->left = insert(node->left, value);
	else
		node->right = insert(node->right, value);
	return node;
}

/* Practice One - AVL Tree Delete */
Node *deleteNode(Node *root, int k)
{
	if (root == NULL)
		return root;

	if (root->value > k)
	{
		root->left = deleteNode(root->left, k);
		return root;
	}
	else if (root->value < k)
	{
		root->right = deleteNode(root->right, k);
		return root;
	}

	if (root->left == NULL)
	{
		Node *temp = root->right;
		delete root;
		return temp;
	}
	else if (root->right == NULL)
	{
		Node *temp = root->left;
		delete root;
		return temp;
	}

	else
	{

		Node *succParent = root->right;

		Node *succ = root->right;
		while (succ->left != NULL)
		{
			succParent = succ;
			succ = succ->left;
		}

		succParent->left = succ->right;

		root->value = succ->value;

		delete succ;
		return root;
	}
}

int main()
{

	Node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	// printf("Rotate to Right\n");
	// rotateRight(root);
	// cout << "height of tree " << height(root) << endl;

	printf("Inorder traversal of the given tree \n");
	inorder(root);

	printf("\nDelete 20\n");
	root = deleteNode(root, 20);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 30\n");
	root = deleteNode(root, 30);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	printf("\nDelete 50\n");
	root = deleteNode(root, 50);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);

	return 0;
}
