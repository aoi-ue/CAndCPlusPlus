/******************************************************************************
filename main.c
author Howard Sin
email howard.sin@digipen.edu
date created 11 June 2019
Brief Description: A starting point reference for link-list assignment
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/* We are going to write simple testing code
to debug our List.c implementation */
int main()
{
	/* Debug variables for us to use */
	struct Node* listHead = NULL;
	// char buffer[256] = {'H','e','l','l','o'};
	
	printf("Starting of AddToEnd\n");
	AddToEnd(&listHead, "MyFirstNode");
	AddToEnd(&listHead, "Haha");
	AddToEnd(&listHead, "LinkedListEZ");
	AddToEnd(&listHead, "Haha");
	PrintList(listHead); 
	printf("There are %d Nodes in the list\n", Count(listHead));
	
	printf("\n\n");
	printf("Starting of AddToFront\n");
	AddToFront(&listHead, "RealFirstNode");
	PrintList(listHead); 
	printf("There are %d Nodes in the list\n", Count(listHead));

	printf("\n\n");
	printf("Starting of InsertAt\n");
	InsertAt(&listHead, "NewAddedNode", 0);
	PrintList(listHead); 
	printf("There are %d Nodes in the list\n", Count(listHead));

	/* Below are functions that are unsolved */
	printf("\n\n"); 
	FreeList(NULL);
	EraseNode(NULL, 0);
	EraseValue(NULL, NULL);
	ReverseList(NULL);
	return 0;
}