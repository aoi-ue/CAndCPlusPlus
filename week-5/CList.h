#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

class List
{
public:
    // Default constructor
    List();

    // TODO: Contruct a list from an integer array
    List(const int *array, int size);

    // TODO: Destructor
    ~List();

    // TODO: adds the item to the front of the list
    void push_front(int value_);
    
    // TODO: adds the item to the end of the list
    void push_back(int value_);
    
    // TODO: removes the first item in the list.
    // If there's nothing to remove, do nothing.
    void pop_front();
    
    // TODO: removes the last item in the list.
    // If there's nothing to remove, do nothing.
    void pop_back();
    
    // TODO: returns the number of items in the list
    int list_size() const;
    
    // TODO: returns true if empty, else false
    bool empty() const;
    
    // TODO: clears the list from all nodes
    void clear();

private:

    // used to build a linked list of integers
    struct Node
    {
        Node(int);              // Constructor
        ~Node();                // Destructor
        Node *next;             // pointer to the next Node
        int data;               // the actual data in the node
        static int nodes_alive; // for keeping track amount of nodes still allocated
    };

    Node *head; // pointer to the head of the list
    Node *tail; // pointer to the last node
    int size;   // number of items in the list

    static int list_count;       // for keeping track number of Lists created

public:
    // Output operator for printing lists (<<)
    friend std::ostream & operator<<(std::ostream & os_, const List &list_);

    // returns the number of Lists that have been created
    static int created_list_count();

    // returns the number of Nodes that are still alive
    static int alive_node_count();

};

#endif
