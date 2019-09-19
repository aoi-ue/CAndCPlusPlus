/******************************************************************************
filename List.c
author Lian Yuhan
email yuhan.lian@digipen.edu.sg
date created 17 Sep 2019
Brief Description: A partial implementation of link-list assignment
******************************************************************************/

#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function will create a node and return it.
If it fails, it returns a NULL value */
struct Node* CreateNode(const char* value)
{
	struct Node* newNode = NULL;
	int stringLength = strlen(value); /* Get the length of our string */ 
	char* newString = malloc(sizeof(char) * stringLength + 1);
	if (newString == NULL)
		return NULL; /* Failed to allocate our string, can't proceed */
	
	newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		free(newString); /* remember that we allocated but now can't use */
		return NULL; /* This case means cannot allocate */
	}
	strcpy(newString, value); /* Copy the string value over */
	
	newNode->next = NULL; /* Ensure next is NULL */	
	/* Time to copy our value to our node */
	newNode->value = newString;
	
	return newNode;
}

/* Adds a node to the end of the list */
void AddToEnd(struct Node** ppList, const char* value)
{
	struct Node* curr = *ppList;
	
	struct Node* newNode = CreateNode(value);
	if (newNode == NULL)
		return; /* Cannot allocate the node */
    
    if (curr == NULL) {
        *ppList = newNode; 
        return; 
    }
    while (curr->next != NULL) {
         curr = curr->next; 
    }
    curr->next = newNode; 
}

/* Adds a node to the front of the list */
void AddToFront(struct Node** ppList, const char* value)
{
	printf("AddToFront Called\n");
// Creating a new node 
	struct Node* curr = *ppList;

	struct Node* newNode = CreateNode(value);
	if (newNode == NULL)
		return; /* Cannot allocate the node */
    
    if (curr == NULL){
        *ppList = newNode;  
        return; 
    }

    newNode->next = curr; 
    *ppList = newNode; 
}

/* Inserts a node in front of given index node */
void InsertAt(struct Node** ppList, const char* value, int index)
{
	printf("InsertAt Called\n");
	struct Node* curr = *ppList;

    struct Node* prev = NULL; 

	struct Node* newNode = CreateNode(value);

	if (newNode == NULL)
		return;

    if (curr == NULL){
        *ppList = newNode;  
        return; 
    }

    int i = 0; 

    while (i < index && curr->next != NULL) {
        ++i; 
        prev = curr; 
        curr = curr->next; 
    }
    if (i == index) {
        if (prev == NULL) {
            *ppList = newNode; 
        }
        else {
            prev->next = newNode; 
        }
        newNode->next = curr;
    }
}

/* Returns number of nodes in the list */
int Count(struct Node* list)
{
	int count = 0;
	while (list != NULL)
	{
		/* We are on an actual node */
		++count;
		list = list->next;
	}
	return count;
}

/* Frees (deletes) all nodes in the list */
void FreeList(struct Node** ppList)
{
	printf("FreeList Called\n");
}

/* Prints values of all nodes in list */
void PrintList(struct Node* list)
{
	int i = 0;
	while (list != NULL)
	{
		/* We are on an actual node */
		printf("Node[%d]: %s\n", i++, list->value);
		list = list->next;
	}
}

/* Erases a node at the given index node */
void EraseNode(struct Node** ppList, int index)
{
    printf("EraseNode Called\n");
}

/* Erase all nodes with the given value in the list */
void EraseValue(struct Node** ppList, const char* value)
{
	printf("EraseValue Called\n");
}

/* Reverses the list */
void ReverseList(struct Node** ppList)
{
	printf("ReverseList Called\n");
}
