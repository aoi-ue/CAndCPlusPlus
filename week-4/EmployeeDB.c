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

// add new employee node  

// remove employee node by ID

// printall 

// search

// quit and remove all entries (free memory)

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
