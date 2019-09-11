#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

/*
int main(int argc, char *argv[]) {
    int input = atoi(argv[1]);
    take in arg 
    printf( "you're taking %d argument's \n", argc-1 );
    printf("you're using this argument %s\n", argv[1]); 

*/ 

int main () {
   char input [30] ="3+2*10";
   char arith [20];
   int i = 0; 

   while (input[i] != '*') {
        sscanf (input,"%d %s",&digit,arith);
        printf ("digit : %d \nArithmatic : %s \n", digit,arith);
        i++; 
    }
   return 0;
}
