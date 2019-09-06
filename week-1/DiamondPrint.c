#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    // input goes here
    int input = atoi(argv[1]);
    if (argc == 2) {
        printf("types: %d\n", argc);         
    }
    printf("number input: %d\n", input); 
    int space = input ; 
    
        for (int i = 0; i < input; i++) { 
        // loop for initially space,  
        // before star printing 
        for (int j = 0; j < space; j++) 
            printf(" "); 
        // Print i+1 stars 
        for (int j = 1;j <= i; j++) 
            printf("%d",j%10); 
        
        for (int j = i-1; j >= 1; j--) 
            printf("%d",j%10);
  
        printf("\n"); 
        space--; 
        } 

        // Loop in reverse 
        space = 0; 

        for (int i = input ; i > 0; i--) { 
        // loop for spaces,  
        // before numeber printing 
        for (int j = 0; j < space; j++) 
            printf(" "); 

        // print numbers 
        for (int j = 1;j <= i; j++) 
            printf("%d",j%10); 
        
        for (int j = i-1; j >= 1; j--) 
            printf("%d",j%10);
  
        printf("\n"); 
        space++; 
        } 

    return 0; 
}
