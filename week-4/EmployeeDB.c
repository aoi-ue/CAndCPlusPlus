#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int ID; // autoincrement
    char *Name;
    int Salary;  //check for zero
    int phoneNumber; //optional
    struct Employee* next; 
};


// add new employee node at the end
void AddToEnd(struct Node** Employee, const char* value)
{
	struct Node* curr = *Employee;
	
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



// remove employee node by ID
void deleteNode(struct Node **head_ref, int key) 
{ 
    // Store head node 
    struct Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 


// printall
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

// search
bool search(struct Node* head, int x) 
{ 
    struct Node* current = head;  // Initialize current 
    while (current != NULL) 
    { 
        if (current->key == x) 
            return true; 
        current = current->next; 
    } 
    return false; 

// quit and remove all entries (free memory)
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

// handle Cases 
int main()
{
    printf("Welcome to our Employee Database!\n");
    char input[100];

    do
    {
        fgets(input, 100, stdin);
        strtok(input, "\n");
        strtok(input, " ");
        if (strcmp(input, "add") == 0)
        {
            struct Employee employee1;

            char *Name = strtok(NULL, " ");
            char *Salary = strtok(NULL, " ");
            char *phoneNumber = strtok(NULL, " ");
            
            employee1.Name = Name;
            employee1.Salary = atoi(Salary);
            if (phoneNumber != NULL) {
                employee1.phoneNumber = atoi(phoneNumber);
            } else {
                employee1.phoneNumber = 0; 
            }

            if (employee1.Salary == 0) {
                printf("Invalid input, please try again."); 
                continue; 
            } 

            printf("Name: %s\n", employee1.Name);
            printf("Salary: %d\n", employee1.Salary);
            printf("Phone Number: %d\n", employee1 .phoneNumber);
        }

        if (strcmp(input, "remove") == 0)
            printf("%s\n", input);
        if (strcmp(input, "printall") == 0)
            printf("%s\n", input);
        if (strcmp(input, "search") == 0)
            printf("%s\n", input);
        if (strcmp(input, "quit") == 0) 
            printf("bye bye!"); 

    } while (strcmp(input, "quit") != 0);

    return 0;
}
