/*********************************************************************************************
filename List.c
author Ho Shuyuan
email shuyuan.ho@digipen.edu
date created 17 September 2019
Brief Description: An implementation of the linked list assignment
**********************************************************************************************/
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
    {
        printf("CreateNode failed (Failed to malloc newString, can't proceed)\n");
        return NULL; /* Failed to allocate our string, can't proceed */
    }
		
	
	newNode = malloc(sizeof(struct Node));
	if (newNode == NULL)
	{
		free(newString); /* remember that we allocated but now can't use */
        printf("CreateNode failed (Failed to malloc newNode, can't proceed)\n");
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
    {
        printf("AddToEnd failed (CreateNode failed)\n");
        return; /* Cannot allocate the node */
    }
		
	
	if (curr == NULL)
	{
		/* We don't even have a single node */
		/* Time to create and set it as the first */		
		/* Malloc is successful, time to link to the first */
		*ppList = newNode;
		return;
	}
	
	/* Means that we are on a node, need to ensure that this is the LAST NODE */
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	
	/* This means we are at the LAST NODE! */
	curr->next = newNode;
}

/* Adds a node to the front of the list */
void AddToFront(struct Node** ppList, const char* value)
{
	struct Node* newNode = CreateNode(value);
    if (newNode == NULL)
    {
        printf("AddToFront failed (CreateNode failed)\n");
        return;
    }
    
    newNode->next = *ppList; /*set (*newNode).next to point to what was the first node*/
    *ppList = newNode; /*set listHead to point to newNode*/    
}

/* Inserts a node in front of given index node */
void InsertAt(struct Node** ppList, const char* value, int index)
{
	struct Node* curr = *ppList;
    struct Node* prev = 0;
    
    struct Node* newNode = CreateNode(value);
	if (newNode == NULL)
    {
        printf("InsertAt failed (CreateNode failed)\n");
        return; /* Cannot allocate the node */
    }
    
    if (curr == NULL)
    {
        printf("InsertAt failed (Linked list is empty, first populate with either AddToEnd or AddToFront function)\n");
        return;
    }
    
    if(index<0)
    {
        printf("InsertAt failed (index has to be a positive integer)\n");
        return;
    }
    
    if(index==0)
    {
        AddToFront(ppList,value);
        return;
    }
    
    for(int i=0;i<index;++i)
    {
        if(i==index-1)
        {
            prev = curr;
        }
        
        curr = curr->next;
        
        if(curr==0)
        {
            printf("InsertAt failed (index node does not exist at time of insertion)\n");
            return;
        }
    }
    newNode->next = curr;
    prev->next = newNode;
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
void FreeList(struct Node** pList)
{
	struct Node* curr = *pList;
    struct Node* temp = 0;
    if(curr == NULL)
    {
        printf("FreeList failed (Linked List is empty)");
        return;
    }
    while(curr != NULL)
    {       
        temp = curr->next;
        free(curr->value);
        free(curr);
        curr = temp;
    }
    *pList = NULL;
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
    struct Node* curr = *ppList;
    struct Node* prev = 0;
    
    if (curr == NULL)
    {
        printf("EraseNode failed (Linked list is empty, first populate with either AddToEnd or AddToFront function)\n");
        return;
    }
    
    if(index<0)
    {
        printf("EraseNode failed (index has to be a positive integer)\n");
        return;
    }
    
    if(index==0)
    {
        *ppList = curr->next;
        free(curr->value);
        free(curr);
        return;        
    }
    
    for(int i=0;i<index;++i)
    {
        if(i==index-1)
        {
            prev = curr;
        }
        
        curr = curr->next;
        
        if(curr==0)
        {
            printf("EraseNode failed (index node does not exist at time of insertion)\n");
            return;
        }
    }
    prev->next = curr->next;
    free(curr->value);
    free(curr);
    
}

/* Erase all nodes with the given value in the list */
void EraseValue(struct Node** ppList, const char* value)
{
    struct Node* curr = *ppList;
    int i = 0;
    printf("EraseValue called for value\"%s\"\n",value);
	while (curr != NULL)
	{
		if(!(strcmp((curr->value),value)))
        {
            EraseNode(ppList, i);
            --i;
        }
		curr = curr->next;
        ++i;
	}    
}

/* Reverses the list */
void ReverseList(struct Node** ppList)
{
	struct Node* curr = *ppList;
    struct Node* temp1 = 0;
    struct Node* temp2 = 0;
    
    if (curr == NULL)
    {
        printf("ReverseList failed (Linked list is empty, first populate with either AddToEnd or AddToFront function)\n");
        return;
    }
    
    temp1 = curr;
    temp2 = curr->next;
    curr->next = NULL;
        
    while(temp2 != NULL)
    {
        curr = temp2;
        temp2 = curr->next;
        curr->next = temp1;
        temp1 = curr;
    }
    
    *ppList = curr;
    
}