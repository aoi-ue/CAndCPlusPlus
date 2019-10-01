#include <stdio.h>
#include <string.h>

int main()
{
    char* names[] = {"zero","one","two","three","four","five","six","seve","eight","nine"}; 

    char name[] = "Sucipta is a BITCH"; 

    printf("%c", *names[5]); 
    printf("%c", name[0]); 

    return 0;
}