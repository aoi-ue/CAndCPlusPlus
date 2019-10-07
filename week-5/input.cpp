#include <iostream>

using namespace std; 

/*
void SwapValueV(int a, int b) {
    int temp = b; 
    b = a; 
    a = temp; 
    cout << a << b << endl; 
}

void SwapValueP(int* a, int* b) {
    int temp = *b; 
    *b = *a; 
    *a = temp; 
    cout << *a << *b << endl; 

}
*/

// void loopArray (int** arr, int row, int col) {
//     for (int i = 0; i < row; i++) {
//         for (int j = 0; j < col; j++) {
//             printf("[%d][%d] %d\n", i, j, arr[i][j]); 
//         }
//     }
// }

int main() {
    int i = 9; 
    int a[10] = {0,1,2,3,4,5,6,7,8,9}; 
    int* ptr = &a[0]; 

    while (i > 0) {
        *(ptr+i) *=2; 
        i /= 3; 
    }

    for (ptr = &a[9]; ptr > &a[0]; --ptr) {
        printf("%d\n", *ptr); 
    }

}
    /*
    int i = 10; 
    int j = 20; 
    SwapValueV(i,j);
    SwapValueP(&i,&j);

    cout << i << endl; 
    cout << j << endl; 
    */
