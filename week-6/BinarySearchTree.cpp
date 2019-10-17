#include <iostream>

using namespace std;

struct Node
{
    int value;
    struct Node *left, *right;
    int height;
};

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

Node *newNode(int value)
{
    Node *temp = new Node;
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node *rotateRight(Node **root)
{
    Node *temp = *root;
    *root = (*root)->left;
    temp->left = (*root)->right;
    (*root)->right = temp;
    return *root; 
}

Node *rotateLeft(Node **root)
{
    Node *temp = *root;
    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;
    return *root; 

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

int balanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *search(Node *node, int value) 
{

    if (node == NULL) return NULL; 
    if (node->value == value) return node; 

    if (node->value < value) 
    {
        return search(node->right, value); 
    } 
    else 
    {
        return search(node->left, value); 
    }
}

Node *insert(Node *node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->value)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rotateRight(&(node));

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return rotateLeft(&(node));

    // Left Right Case
    if (balance > 1 && value > node->left->value)
    {
        node->left = rotateLeft(&(node)->left);
        return rotateRight(&(node));
    }
    // Right Left Case
    if (balance < -1 && value < node->right->value)
    {
        node->left = rotateRight(&(node)->right);
        return rotateLeft(&(node));
    }
    return node;
}

Node *deleteNode(Node *node, int value)
{
    if (node == NULL)
        return node;

    if (node->value > value)
    {
        node->left = deleteNode(node->left, value);
        return node;
    }
    else if (node->value < value)
    {
        node->right = deleteNode(node->right, value);
        return node;
    }
    // delete right selected node
    if (node->left == NULL)
    {
        Node *temp = node->right;
        delete node;
        return temp;
    }
    // delete left selected node
    else if (node->right == NULL)
    {
        Node *temp = node;
        delete node;
        return temp;
    }
	else
	{
		Node *succParent = node;
		Node *succ = node->right;

		while (succ->left != NULL)
		{
			succParent = succ;
			succ = succ->left;
		}

		node->value = succ->value;

		delete succ;
		succParent->left = NULL; 
		return node;
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

    // Node *item = search(root, 40); 
    // (item == NULL) ? cout << "Not Found" : cout << "Search found: " << item->value << endl; 

    cout << "Inorder traversal of the AVL tree" << endl; 
    inorder(root);
    cout << "Height of Tree is at " << height(root) << endl;

    cout << "Inorder traversal of the delete one node AVL tree" << endl; 
    root = deleteNode(root, 50);
    inorder(root);
    cout << "Height of Tree is at " << height(root) << endl;

    cout << "Inorder traversal of the delete two node AVL tree" << endl; 
    root = deleteNode(root, 70);
    inorder(root);
    cout << "Height of Tree is at " << height(root) << endl;

    cout << "Inorder traversal of the delete three node AVL tree" << endl; 
    root = deleteNode(root, 40);
    inorder(root);
    cout << "Height of Tree is at " << height(root) << endl;

}