#include "CList.h"

using namespace std; 

List::Node::Node(int value_)
	: next(nullptr), data(value_)
{
	++nodes_alive;
}
 
List::Node::~Node() 
{
	--nodes_alive;
}

List::~List()
{
	list_count--; 
	clear(); 
}

int List::Node::nodes_alive = 0;
int List::list_count = 0;

List::List() 
{ 
	head = nullptr; 
	tail = nullptr; 
	List::list_count++; 
}

List::List(const int *array, int size) 
{	
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
	List::list_count++; 
}

void List::push_front(int value_) 
{
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

void List::push_back(int value_) 
{
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

void List::pop_front() 
{
	if (head == nullptr) 
	{
		return; 
	} else {
		Node* next = head->next; 

		if (head == tail) 
		{
			tail = next; 
		}
		delete head;
		head = next; 
		--size; 
	}
}

void List::pop_back() 
{
	Node* prev = nullptr; 
	Node* curr = head; 

	if (curr == NULL) {
		return; 
	} 

	while (curr->next != NULL) {
		prev = curr; 
		curr = curr->next;  
	}

	if (head == tail) {
		head = nullptr; 
		tail = nullptr; 
		delete curr; 
		return; 
	}

	delete curr; 
	tail = prev; 
	--size;
	prev->next = NULL; 
}


void List::clear() 
{
	Node* curr = head;
    Node* temp = nullptr;
    if(curr == nullptr) 
    {
        cout << "FreeList failed (Linked List is empty)" << endl; 
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

int List::list_size() const 
{
	Node* curr = head; 
	int i = 0;

	while (curr != NULL)
	{
		i++; 
		curr = curr->next;
	}
	return i; 
}

bool List::empty() const 
{
	return head == nullptr; 
}

int List::created_list_count() 
{
	return list_count;
}

int List::alive_node_count() 
{
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
