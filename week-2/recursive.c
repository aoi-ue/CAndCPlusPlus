#include <stdio.h> 

int p = 2; 

void recursion (int p) {
    if (p>0) {
        printf("hello");
        recursion(p-1);
    }
}

void main() { 
    recursion(p); 
}
