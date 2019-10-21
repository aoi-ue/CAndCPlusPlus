#include <iostream> 

using namespace std; 

struct Node {
    const char* value; 
    Node* next; 
};

class LinkedList {
    public: 
        void AddToEnd(char* value); 
        Node* insert(char* value); 
        Node* remove(); 
        int count(); 
        void printAll(); 
    
    private: 
        Node* CreateNode(char* value); 
        void PrintList(struct Node* list); 
        Node* head = nullptr; 
}; 

void LinkedList::AddToEnd(char* value)
{
    struct Node* curr = head;

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
		head = newNode;
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

void LinkedList::printAll() 
{
    PrintList(head); 
    return; 
}
 

void LinkedList::PrintList(struct Node* list)
{
	int i = 0;
	while (list != NULL)
	{
		/* We are on an actual node */
		printf("Node[%d]: %s\n", i++, list->value);
		list = list->next;
	}
}

Node* LinkedList::CreateNode(char* value) 
{
    struct Node* newNode = NULL; 
    newNode = new Node;
    newNode->value = value; 
    newNode->next = nullptr; 
    return newNode; 
} 

int main() {
    LinkedList List1;
    List1.AddToEnd((char*) "str");
    List1.AddToEnd((char*) "dex");
    List1.printAll(); 
}

