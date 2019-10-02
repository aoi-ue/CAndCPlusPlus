#include "CList.h"

using namespace std; 

List::Node::Node(int value_)
	: next(nullptr), data(value_)
{
	++nodes_alive;
}
 
List::Node::~Node() {
	--nodes_alive;
}

int List::Node::nodes_alive = 0;
int List::list_count = 0;

// List::List(){cout << "hello" << endl; cout << "bye";}  

List::List() { 
	head = nullptr; 
	tail = nullptr; 
}

List::List(const int *array, int size) {
	
	if (size == 0) {
		cout << "are you sure? empty list is created." << endl; 
		head = nullptr; 
		tail = nullptr;
		return; 
	}

	Node* curr = nullptr;
    Node* temp = nullptr;

	for (int i = 0; i < size; ++i) {
		temp = new Node(array[i]); 
		if (i == 0) head = temp; 
		if (i > 0) {
			curr->next = temp; 
		}
		curr = temp; 
		if (i == size - 1) tail = temp; 
	}
}

void List::push_front(int value_) {
	Node* newNode = new Node(value_); 
	if (newNode == nullptr) {
		cout << "memory allocation failed, no node" << endl; 
		return; 
 	} 
	if (head == nullptr) {
		head = tail = newNode; 
		return; 
	}
	newNode->next = head; 
	head = newNode; 
}


void List::push_back(int value_) {
	Node* newNode = new Node(value_); 
	if (newNode == nullptr) {
		cout << "memory allocation failed, no node" << endl; 
		return; 
 	} 
	if (tail == nullptr) {
		head = tail = newNode; 
		return; 
	}
	tail->next = newNode; 
	tail = newNode; 
}


List::~List(){}

void List::clear() {

	Node* curr = head;
    Node* temp = nullptr;
    if(curr == nullptr) 
    {
        printf("FreeList failed (Linked List is empty)");
        return;
    }
    while(curr != nullptr)
    {    
        temp = curr->next;
        delete curr;
        curr = temp;
	}

	head = tail = nullptr; 
}

void List::pop_front() {

	if (head == nullptr) {
		cout << "Nothing to pop from an empty list";
		return; 
	} else {
		Node* next = head->next; 

		if (head == tail) {
			tail = next; 
		}
		
		delete head;
		head = next; 
		--size; 
	}
}

void List::pop_back() {

}


int List::created_list_count() {
	return list_count;
}

int List::alive_node_count() {
	return Node::nodes_alive;
}

std::ostream& operator<<(std::ostream & os_, const List & list_)
{
	List::Node * itr = list_.head;
	while (itr != nullptr)
	{
		os_ << itr->data << ((itr->next != nullptr) ? "," : "");
		itr = itr->next;
	}
	return os_;
}


// List::modifyhead(Node* ptr)
// {
// 	head = ptr;
// }

/*
int main()
List haha;
haha.modifyhead(0x345346456);
*/
