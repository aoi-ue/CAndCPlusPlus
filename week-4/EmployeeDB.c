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

void deleteNode(struct Employee **ppEmployee, int ID)
{
    // Store head node
    struct Employee *temp = *ppEmployee, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->ID == ID)
    {
        *ppEmployee = temp->next; // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->ID != ID)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

void PrintList(struct Employee *list)
{
    int i = 0;
    while (list != NULL)
    {
        /* We are on an actual node */
        printf("Entry[%d]: %d: %s: %d: %d\n", i++, list->ID, list->Name, list->Salary, list->phoneNumber);

        list = list->next;
    }
}

int Search(struct Employee *head, int mode)
{
    struct Employee *curr = head; // Initialize current
    while (curr->next != NULL)
    {
        if (curr->ID == mode)
            printf("found");
        curr = curr->next;
    }
    return 0;
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
    unsigned long count = 0;
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
    int latestID = 1;

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

            latestID++;

            printf("SUCCESS\n");

            // PrintList(employeeHead);
            // printf("There are %d Nodes in the list\n", Count(employeeHead));
        }
        if (strcmp(input, "remove") == 0)
        {
            char *ID = strtok(NULL, " ");
            int aID;

            if (ID == NULL || isANum(ID) == 0)
            {
                printf("Invalid input, please try again.\n");
                continue;
            }
            else
            {
                aID = atoi(ID);
            }

            deleteNode(&employeeHead, aID);

            printf("SUCCESS\n");

            // PrintList(employeeHead);
            // printf("There are %d Nodes in the list\n", Count(employeeHead));
        }
        if (strcmp(input, "printall") == 0)
        {
            PrintList(employeeHead);
        }

        if (strcmp(input, "search") == 0)
        {
            char *mode = strtok(NULL, " ");
            char *Item = strtok(NULL, " ");

            if (strcmp(mode, "-id") == 0)
            {
                printf("id searching");
                int aItem = atoi(Item);
                Search(employeeHead, aItem);
            }

            if (strcmp(mode, "-name") == 0)
            {
                printf("name");
            }

            if (strcmp(mode, "-salary") == 0)
            {
                printf("sal");
            }

            if (strcmp(mode, "-phonenum") == 0)
            {
                printf("pn");
            }
        }

        if (strcmp(input, "quit") == 0)
        {
            free(employeeHead);
            printf("bye bye!\n");
            break;
        }

    } while (strcmp(input, "quit") != 0);
}
