#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int ID; // autoincrement
    char *Name;
    int Salary;      //check for zero
    int phoneNumber; //optional
    struct Employee* next; 
};

// create node 
struct Employee* CreateNode(const char* Name)
// include const char* Salary, const char* phoneNumber)
{
	struct Employee* newNode = NULL;
	int nameLength = strlen(Name); /* Get the length of our string */ 
    // int salaryLength = strlen(Salary); /* Get the length of our string */ 
	// int phoneNumberLength = strlen(phoneNumber); /* Get the length of our string */ 
	char* nameString = malloc(sizeof(char) * nameLength + 1);
	if (nameString == NULL)
		return NULL; /* Failed to allocate our string, can't proceed */
	
	newNode = malloc(sizeof(struct Employee));
	if (newNode == NULL)
	{
		free(nameString); /* remember that we allocated but now can't use */
		return NULL; /* This case means cannot allocate */
	}
	strcpy(nameString, Name); /* Copy the string value over */
	
	newNode->next = NULL; /* Ensure next is NULL */	
	/* Time to copy our value to our node */
	// newNode->ID = newString;
    newNode->Name = nameString; 
	
	return newNode;
}

// add node 

// remove node by ID

// printall 

// search

// quit and remove all entries (free memory)

// Create a menu page and Emun for switch cases
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

            // call createNode
            char *Name = strtok(NULL, " ");
            char *Salary = strtok(NULL, " ");
            char *phoneNumber = strtok(NULL, " ");
            
            CreateNode(Name); 

            employee1.Name = Name;
            employee1.Salary = atoi(Salary);
            if (phoneNumber != NULL) {
                employee1.phoneNumber = atoi(phoneNumber);
            } else {
                employee1.phoneNumber = 0; 
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
            printf("%s\n", input);

    } while (strcmp(input, "quit") != 0);

    return 0;
}
