#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int ID; // autoincrement
    char *Name;
    int Salary;      //check for zero
    int phoneNumber; //optional
};

// add

// remove

// printall

// search

// quit and remove all entries (free memory)

// Create a menu page and Emun for switch cases
int main()
{   
    char input[100];

    do {
        fgets(input, 100, stdin); 
        strtok(input, "\n"); 
        strtok(input, " ");
        if (strcmp(input, "add") == 0) {
            struct Student student1 = {
                10, "Yuhan", 1000, 1000  
            }; 

            char *ID = strtok(NULL, " "); 
            printf("ID%s\n:",ID); 

            char *Name = strtok(NULL, " "); 
            printf("Name%s\n:",Name); 

            char *Salary = strtok(NULL, " ");      
            printf("Salary%s\n:",Salary); 

            char *phoneNumber = strtok(NULL, " "); 
            printf("phone%s\n: ",phoneNumber); 

            student1.ID = atoi(ID); 
            student1.Name = Name; 
            student1.Salary = atoi(Salary); 
            student1.phoneNumber = atoi(phoneNumber); 

            printf("after in struct: \n");
            printf("ID   : %d", student1.ID); 
        }


        if (strcmp(input, "remove") == 0) printf("%s\n",input); 
        if (strcmp(input, "printall") == 0) printf("%s\n",input); 
        if (strcmp(input, "search") == 0) printf("%s\n",input); 
        
    }
    while (strcmp(input,"quit") != 0); 


    return 0;
}
