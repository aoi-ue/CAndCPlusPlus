#include "CList.h"

using namespace std; 

int main() {
    //std::cout << "Testing" << std::endl; 
    int array [] = {1,2,3,4,5}; 
    int size = 5; 

    List a(array, size); 
    cout << a << endl << "List now contains" << endl; 

    a.push_front(0); 
    cout << a << endl << "List contains a new number at front" << endl; 

    a.push_back(6); 
    cout << a << endl << "List contains a new number at back" << endl; 

	a.clear(); 
    cout << a << endl << "List contains nothing" << endl; 

    a.push_front(0); 
    cout << a << endl << "Pushing to front into List contains" << endl; 

    a.push_back(6); 
    cout << a << endl << "List contains a new number at back" << endl; 

    a.pop_front(); 
    cout << a << endl << "Remove First Node from List" << endl; 

    a.pop_back(); 
    cout << a << endl << "Remove Last Node from List" << endl; 

    // a.pop_front(); 
    // cout << a << endl << "Remove First from List" << endl; 

    // a.pop_front(); 
    // cout << a << endl << "Remove First from List" << endl; 

	return 0;  
}
