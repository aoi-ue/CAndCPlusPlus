#include <stdio.h> 

void f(int* xPtr) {
    *xPtr+= 1;
}

int main() {
    int x = 0; 
    f(&x); 
    f(&x); 
    f(&x); 
    printf("%d", x); 
}