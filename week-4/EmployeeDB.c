#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    int ID; // autoincrement
    char *Name;
    int Salary;      //check for zero
    int phoneNumber; //optional
    struct Employee *next;
};

struct Employee *CreateNode(int ID, const char *Name, int Salary, int phoneNumber)
{
    struct Employee *newNode = NULL;

    int nameLength = strlen(Name); /* Get the length of our string */
    char *newString = malloc(sizeof(char) * nameLength + 1);
    if (newString == NULL)
        return NULL; /* Failed to allocate our string, can't proceed */

    newNode = malloc(sizeof(struct Employee));
    if (newNode == NULL)
    {
        free(newString); /* remember that we allocated but now can't use */
        return NULL;     /* This case means cannot allocate */
    }

    strcpy(newString, Name); /* Copy the string value over */

    newNode->next = NULL; /* Ensure next is NULL */
                          /* Time to copy our value to our node */
    newNode->ID = ID;
    newNode->Name = newString;
    newNode->Salary = Salary;
    newNode->phoneNumber = phoneNumber;

    return newNode;
}

// add new employee node at the end
void AddToEnd(struct Employee **ppEmployee, int ID, const char *Name, int Salary, int phoneNumber)
{
    struct Employee *curr = *ppEmployee;

    struct Employee *newNode = CreateNode(ID, Name, Salary, phoneNumber);
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
        *ppEmployee = newNode;
        return;
    }

    /* Means that we are on a node, need to ensure that this is the LAST NODE */
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    /* This means we are at the LAST NODE! */
    curr->next = newNode;
}

void PrintList(struct Employee *list)
{
    int i = 0;
    while (list != NULL)
    {
        /* We are on an actual node */
        printf("Node[%d]: %d\n", i++, list->ID);
        list = list->next;
    }
}

int Count(struct Employee *list)
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

int isANum(char *input)
{
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= '0' && input[i] <= '9')
        {
            count++;
        }
    }
    int result = count == strlen(input) ? 1 : 0;

    return result;
}

int main()
{

    printf("Welcome to our Employee Database!\n");
    char input[100];
    int latestID = 0;

    struct Employee *employeeHead = NULL;

    do
    {
        fgets(input, 100, stdin);
        strtok(input, "\n");
        strtok(input, " ");
        if (strcmp(input, "add") == 0)
        {

            char *Name = strtok(NULL, " ");
            char *Salary = strtok(NULL, " ");
            char *phoneNumber = strtok(NULL, " ");

            int aSalary;
            int aPhoneNumber;

            // reject non-number 
            if (Salary == NULL || isANum(Salary) == 0)
            {
                printf("Invalid input, please try again.\n");
                continue;
            }
            else
            {
                aSalary = atoi(Salary);
            }

            if (phoneNumber != NULL)
            {
                aPhoneNumber = atoi(phoneNumber);
            }
            else
            {
                aPhoneNumber = 0;
            }

            AddToEnd(&employeeHead, latestID, Name, aSalary, aPhoneNumber);
    
            printf("SUCCESS\n"); 
        }
        if (strcmp(input, "remove") == 0)
            printf("%s\n", input);
    } while (strcmp(input, "quit") != 0);
}