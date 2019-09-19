#include <stdio.h> 
#include <stdlib.h>

int arr[] = {4,3,2,1}; 
int* size = sizeof(arr)/sizeof(arr[0]); 

void swap(int x, int y) {
    int temp = x; 
    x = y;
    y = temp; 
}

void bubbleSort(arr, size) {
    if (size > 0) {
        printf("%d", arr[size]); 
        bubbleSort(arr, size-1); 
    }
}

int main() {
    bubbleSort(arr, size); 
    return 0; 
}
 