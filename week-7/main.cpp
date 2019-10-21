#include <iostream> 
#include "AVL.h"

int main() {
    AVL tree;

    tree.insert(50); 
    tree.insert(30); 
    tree.insert(20); 
    tree.insert(80); 

    if (!tree.remove(80)) 
    {
        cout << "80 Not Found" << endl; 
    } 

    tree.printall();

    if (!tree.remove(10)) 
    {
        cout << "10 Not Found" << endl; 
    } 
    
    cout << endl; 
    tree.printall(); 

}