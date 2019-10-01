#include <stdio.h>
#include <stdlib.h>

//*** Structure for the Binary Tree Node. Do not modify ***//
struct BTNode
{
    int value;
    struct BTNode *left_child;
    struct BTNode *right_child;
};

//*** Recursive Function to Insert Values in the Ordered Binary Tree/Binary Search Tree ***//
void insert(struct BTNode *Node, int val)
{
    if (val > Node->value)
    {
        if (Node->right_child == NULL)
        {
            Node->right_child = (struct BTNode *)malloc(sizeof(struct BTNode));
            Node->right_child->value = val;
            Node->right_child->left_child = NULL;
            Node->right_child->right_child = NULL;
        }
        else
        {
            insert(Node->right_child, val);
        }
    }
    else
    {
        if (Node->left_child == NULL)
        {
            Node->left_child = (struct BTNode *)malloc(sizeof(struct BTNode));
            Node->left_child->value = val;
            Node->left_child->left_child = NULL;
            Node->left_child->right_child = NULL;
        }
        else
        {
            insert(Node->left_child, val);
        }
    }
}

/****** Practice Part 1:******/

/******** TASK1 ********/
//*** Write Recursive Function to Traverse the Binary Tree in Preorder. No Global Variable or Loop Should be Used ***//
void preorder(struct BTNode *Node)
{
    if (Node == NULL) return; 
    printf("%d -> ", Node->value);
    preorder(Node->left_child);
    preorder(Node->right_child);
}

/******** TASK2 ********/
//*** Write Recursive Function to Traverse the Binary Tree in Inorder. No Global Variable or Loop Should be Used ***//
void inorder(struct BTNode *Node)
{
    if (Node == NULL) return; 
    inorder(Node->left_child);
    printf("%d -> ", Node->value);
    inorder(Node->right_child);
}

/******** TASK3 ********/
//*** Write Recursive Function to Traverse the Binary Tree in Postorder. No Global Variable or Loop Should be Used ***//
void postorder(struct BTNode *Node)
{
    if (Node == NULL) return; 
    postorder(Node->left_child);
    postorder(Node->right_child);
    printf("%d -> ", Node->value);
}

//*** Do not modify main()***//
int main()
{
    struct BTNode *Head;

    Head = (struct BTNode *)malloc(sizeof(struct BTNode));
    Head->value = 50;
    Head->left_child = NULL;
    Head->right_child = NULL;

    insert(Head, 100);
    insert(Head, 75);
    insert(Head, 125);
    insert(Head, 30);
    insert(Head, 40);
    insert(Head, 20);

    printf("*** Preorder ***\n");
    preorder(Head);
    printf("\n");
    printf("*** Inorder ***\n");
    inorder(Head);
    printf("\n");
    printf("*** Postorder ***\n");
    postorder(Head);
    return 0;
}