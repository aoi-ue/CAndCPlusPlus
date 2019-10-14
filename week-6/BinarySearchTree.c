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

/****** Practice Part 3:******/

struct BTNode * minValueNode(struct BTNode* node) 
{ 
    struct BTNode* current = node; 
  
    while (current && current->left_child != NULL) 
        current = current->left_child; 
  
    return current; 
} 

struct BTNode* deleteNode(struct BTNode* root, int value) 
{ 
    if (root == NULL) return root; 
  
    if (value < root->value) 
        root->left_child = deleteNode(root->left_child, value); 
  
    else if (value > root->value) 
        root->right_child = deleteNode(root->right_child, value); 
  
    else
    { 
        if (root->left_child == NULL) 
        { 
            struct BTNode *temp = root->right_child; 
            free(root); 
            return temp; 
        } 
        else if (root->right_child == NULL) 
        { 
            struct BTNode *temp = root->left_child; 
            free(root); 
            return temp; 
        } 
  
        struct BTNode* temp = minValueNode(root->right_child); 
  
        root->value = temp->value; 
  
        root->right_child = deleteNode(root->right_child, temp->value); 
    } 
    return root; 
} 

/****** Practice Part 2:******/

/******** TASK1 ********/
//*** Write Recursive Function to Count the Number of Vertices. The count should be the function parameter, and not a Static or Global Variable***//
int countV1(struct BTNode* Node)
{
    if (Node == NULL) return 0; 
    return countV1(Node->left_child) + countV1(Node->right_child) + 1; 
} 

/******** TASK2 ********/
//*** Write Recursive Function to Count the Number of Vertices. The count should be a pointer, and not a Static or Global Variable***//
void countV2(struct BTNode* Node, int* count)
{
    if (Node == NULL) return; 
    *count+=1; 
    countV2(Node->left_child, count); 
    countV2(Node->right_child, count); 

}

/******** TASK3 ********/
//*** Write Recursive Function to Print All the Edges ***//
void edgePrint(struct BTNode* Node)
{
    if (Node == NULL) return; 
    if (Node->left_child!=NULL) {
        edgePrint(Node->left_child); 
        printf("%d-%d\n", Node->value, Node->left_child->value); 
    }
    if (Node->right_child!=NULL) {    
        edgePrint(Node->right_child); 
        printf("%d-%d\n", Node->value, Node->right_child->value); 
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

//

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


	printf("*** Number of Vertices V1: %d ***\n",countV1(Head));	
	//*********** You can Modify below this point **********//
	//******************** For countV2 *********************//
	int count = 0; 
    countV2(Head, &count);
	printf("*** Number of Vertices V2: %d ***\n",count);
	//********* You CANNOT Modify below this point ********//

	printf("\n");
	printf("*** Edges ***\n");
	edgePrint(Head);

    printf("*** Preorder ***\n");
    preorder(Head);
    printf("\n");
    printf("*** Inorder ***\n");
    inorder(Head);
    printf("\n");
    printf("*** Postorder ***\n");
    postorder(Head);

    printf("\n \nInorder traversal of the given tree \n"); 
    inorder(Head); 
  
    printf("\n \nDelete 20\n"); 
    deleteNode(Head, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(Head); 
  
    printf("\n \nDelete 30\n"); 
    deleteNode(Head, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(Head); 
  
    printf("\n \nDelete 50\n"); 
    deleteNode(Head, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(Head);

    return 0;
}