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

bool rotateRequired(Node *node)
{
    int difference = height(node->left) - height(node->right);
    if (difference >= -1 && difference <= 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/* Practice Two - AVL Tree insertion */
Node *insert(Node *node, int value)
{
    if (node == NULL)
        return newNode(value);
    if (value < node->value)
    {
        node->left = insert(node->left, value);
        if (rotateRequired(node))
        {
            rotateRight(&(node));
        }
    }
    else {
        node->right = insert(node->right, value);
        if (rotateRequired(node))
        {
            rotateLeft(&(node));
        }
    }
    return node;
}

int main()
{

    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 100);
    root = insert(root, 10);
    root = insert(root, 110);
    root = insert(root, 120);
    root = insert(root, 40);


    cout << "If 1, rotate required " << rotateRequired(root) << endl;

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    cout << "Check Height" << height(root) << endl;

    printf("Inorder traversal of the rotated tree \n");
    inorder(root);

    cout << "Check Height " << height(root) << endl;
}