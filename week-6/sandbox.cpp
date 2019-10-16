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

Node *newNode(int item)
{
    Node *temp = new Node;
    temp->value = item;
    temp->left = temp->right = NULL;
    return temp;
}

void rotateRight(Node **root)
{
    Node *temp = *root;
    *root = (*root)->left;
    temp->left = (*root)->right;
    (*root)->right = temp;
}

void rotateLeft(Node **root)
{
    Node *temp = *root;
    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;
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

/* Practice Two - AVL Tree insertion */
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
        rotateRight(&(node));

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        rotateLeft(&(node));

    // Left Right Case
    if (balance > 1 && value > node->left->value)
    {
        rotateLeft(&node->left);
        rotateRight(&(node));
    }
    // Right Left Case
    if (balance < -1 && value < node->right->value)
    {
        rotateRight(&node->right);
        rotateLeft(&(node));
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
        Node *temp = node->right;
        node->value = temp->value;
        node->right = deleteNode(node->right,temp->value);
    }
}

int main()
{

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    // root = insert(root, 40);
    // root = insert(root, 50);

    printf("Inorder traversal of the AVL tree \n");
    inorder(root);

    cout << "Height of Tree is at " << height(root) << endl;

    printf("Inorder traversal of the AVL tree \n");
    inorder(root);

    cout << "Height of Tree is at " << height(root) << endl;

    root = deleteNode(root, 10);
    cout << "Height of Tree is at " << height(root) << endl;
    printf("Inorder traversal of the delete one node AVL tree \n");
    inorder(root);
}