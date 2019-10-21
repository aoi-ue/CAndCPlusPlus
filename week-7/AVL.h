#include <iostream> 

using namespace std; 

struct Node {
    int value; 
    Node* right; 
    Node* left; 
}; 

class AVL {
    public: 
        bool remove(int value); 
        Node* insert(int value); 
        void printall(); 
        int height(); 

    private: 
        Node* root = NULL; 
        Node* insertNode(Node* node, int value);
        Node* deleteNode(Node* node, int value, bool* result);
        Node* newNode(int value); 
        
        int balanceFactor(Node* node); 
        Node* rotateRight(Node** node); 
        Node* rotateLeft(Node** node); 
        void inorder(Node* node); 
        int findHeight(Node* node); 
}; 