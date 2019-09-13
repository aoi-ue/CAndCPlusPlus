/*---------------------------------------------------------------
Student: Lian Yuhan
Filename: Calculator.c
Email: daniel.l@digipen.edu
Date: 10th Sep 2019
Description: A basic calculator for integers written in C. 
-----------------------------------------------------------------*/

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

int i, j;
char tmp[10]; 
char operator[20]; 
int arr[20];  
int sum;  

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Invalid usage: <ProgramName>.exe <MathExpression:string>");  
        return 1;        
    }
    char* input = argv[1];
    // loop a string to check for number and operator 
    for (i = 0; input[i] != '\0' ; i++) {
    // store number and operator in variable 
        if (input[i] >= '0' && input[i] <= '9') {
            tmp[strlen(tmp)] = input[i]; 
            tmp[strlen(tmp)+1] = '\0';
        } 
        else if (input[i] == '*' ||input[i] == '-' ||input[i] == '+' ||input[i] == '/') {
            arr[j] = atoi(tmp); 
            printf("%n", arr); 
            operator[j] = input[i]; 
            
            for (int k = 0; k < 10; k++) {
                tmp[k] = '\0'; 
            }
            j++; 
        }
        if (input[i + 1] == '\0') {
            arr[j] = atoi(tmp);
        }
    }
    // testing if loop is working
    // for (i=0; i < 4; i++) {
    //     printf("array:%d\n", arr[i]);
    // }
    //  for (i=0; i < 4; i++) {
    //     printf("op:%c\n", operator[i]);
    // }

    for (i = 0; i <= j; i++) {
        if (i == 0) {
            sum = arr[0]; 
        } 

        switch(operator[i-1]) {
            case '+': 
            sum += arr[i]; 
            break; 

            case '-': 
            sum -= arr[i]; 
            break; 

            case '*': 
            sum *= arr[i]; 
            break;

            case '/': 
            sum /= arr[i]; 
            break;
        }
    }
    printf("sum:%d", sum); 
}
