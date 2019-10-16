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

int rotateRequired(Node *node)
{
    if (node == NULL) return 0;
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

    int balance = rotateRequired(node); 

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

int main()
{

    Node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 20);

    printf("Inorder traversal of the AVL tree \n");
    inorder(root);

    cout << "Height of Tree is at " << height(root) << endl;
}