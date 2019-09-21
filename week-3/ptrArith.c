#include <stdio.h> 

int main() {
    int a[10] = {0,2,4,6,8,10}; 
    int i = 10; 
    int *p = &a[3]; 

    printf("%d and %d\n", *(p+1), a[0]);


 }