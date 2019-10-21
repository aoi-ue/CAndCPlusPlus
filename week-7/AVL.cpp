#include <iostream> 
#include "AVL.h"

using namespace std;

int AVL::height() 
{
    return findHeight(root);  
}

int AVL::findHeight(Node *node)
{
    if (node == NULL)
        return -1;
    int leftH = findHeight(node->left);
    int rightH = findHeight(node->right);

    if (leftH > rightH)
    {
        return leftH + 1;
    }
    else
    {
        return rightH + 1;
    }
}

int AVL::balanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return findHeight(node->left) - findHeight(node->right);
}

Node* AVL::insert(int value)
{
    root = insertNode(root, value);
    return root; 
}

Node* AVL::insertNode(Node* node, int value)
{
    if (node == NULL)
        return newNode(value);

    if (value < node->value)
    {
        node->left = insertNode(node->left, value);
    }
    else
    {
        node->right = insertNode(node->right, value);
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

bool AVL::remove(int value)
{
    bool result = false;
    root = deleteNode(root, value, &result);
    return result; 
}

Node *AVL::deleteNode(Node *node, int value, bool* resultPtr)
{
    if (node == NULL)
        return node;

    if (node->value > value)
    {
        node->left = deleteNode(node->left, value, resultPtr);
    }
    else if (node->value < value)
    {
        node->right = deleteNode(node->right, value, resultPtr);
    }
    else
    {
        *resultPtr = true; 
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
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else
        { // for parent with two children
            Node *succParent = node;
            Node *succ = node->right;

            // selecting the right tree's most bottom left node
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

    int balance = balanceFactor(node);

    // Left Left Case
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(&(node));

    // Right Right Case
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(&(node));

    // Left Right Case
    if (balance > 1 && balanceFactor(node->left) < 0)
    {
        node->left = rotateLeft(&(node)->left);
        return rotateRight(&(node));
    }
    // Right Left Case
    if (balance < -1 && balanceFactor(node->right) > 0)
    {
        node->left = rotateRight(&(node)->right);
        return rotateLeft(&(node));
    }
    return node;
}


void AVL::printall() 
{
    inorder(root); 
}

void AVL::inorder(Node* node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

Node* AVL::newNode(int value) 
{
    Node* temp = new Node; 
    temp->value = value; 
    temp->left = temp->right = NULL; 
    return temp; 
}

Node* AVL::rotateRight(Node** node)
{
    Node *temp = *node; 
    *node = (*node)->left;
    temp->left = (*node)->right; 
    (*node)->right = temp; 
    return *node;  
}

Node* AVL::rotateLeft(Node **root)
{
    Node *temp = *root;
    *root = (*root)->right;
    temp->right = (*root)->left;
    (*root)->left = temp;
    return *root;
}