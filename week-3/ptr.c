#include <stdio.h> 

int main()
{
    int *ptr;
    int x;
 
    ptr = &x;
    *ptr = 0;
 
    printf(" x = %dn", x);
    printf(" ptr = %dn", ptr);
    printf(" *ptr = %dn", *ptr);
 
    *ptr += 5;
    printf(" x  = %dn", x);
    printf(" *ptr = %dn", *ptr);
 
    (*ptr)++;
    printf(" x = %dn", x);
    printf(" *ptr = %dn", *ptr);
 
    return 0;
}

// simple pointer and de-referencing
// void fun (int* p){
//     int q = 10; 
//     p = &q; 
//     printf("%d\n", *p); 
// }

// int main () {
//     int r = 20; 
//     int* p = &r; 
//     fun(p); 
//     printf("%d\n", *p); 
//     printf("end of line"); 
//     return 0; 
// }

