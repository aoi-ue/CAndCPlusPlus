/* strtok example */
#include <stdio.h>
#include <string.h>

int isANum(char* input) {
    int count = 0; 
    for (int i = 0; input[i] != '\0' ; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            count++; 
        }
    }
    count == strlen(input) ? printf("yes!") : printf("no!"); 
    return 0; 
}

int main ()
{
  isANum(""); 
  return 0;
}
