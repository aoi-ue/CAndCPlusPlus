//============================================================================
// Name        : CET113_lab_8.cpp
// Author      : STANFORD
// Version     :
// Copyright   : Want to copy, don't copy blindly! Copy smartly!
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include "CList.h"

/**int main(int argc, char *argv[])**/
int main()
{
	int testArray[] = {1,2,3,4,5,6,7,8,9,10};//#debug

	std::cout << "CET113_lab_8 First C++ assignment." << std::endl;

	List *aCList = new List();

	/*
	 * TEST 1
	 * */
	std::cout << "Test case 1: default constructor" << std::endl;
	std::cout << "cout my list: " << *aCList << std::endl;
	std::cout << "is list aCList empty? (expected true, 1): " << aCList->empty() << std::endl;
	std::cout << "size of the list (expected 0): " << aCList->list_size() << std::endl;
	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 1): " << List::created_list_count() << std::endl;
	aCList->clear();
	aCList->clear();//double clear
	std::cout << "\naCList->clear();" << std::endl;
	std::cout << "is list aCList empty? (expected true, 1): " << aCList->empty() << std::endl;
	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 1): " << List::created_list_count() << std::endl;
	delete aCList;
	std::cout << "\ndelete aCList;" << std::endl;
	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 0): " << List::created_list_count() << std::endl;
	std::cout << "Test case 1 END: default constructor\n==========\n" << std::endl;

	/*
	 * TEST 2
	 * */
	std::cout << "Test case 2: push front and back. Test to see if pushing when list is empty/not empty, and push from front/back." << std::endl;
	aCList = new List();
	aCList->clear();
	aCList->push_front(2);
	aCList->push_front(1);
	aCList->push_front(0);
	aCList->push_back(3);
	aCList->push_back(4);
	aCList->push_back(5);
	std::cout << "cout my list (push front, front, push back, back): " << *aCList << std::endl;
	aCList->clear();
	aCList->push_back(3);
	aCList->push_back(4);
	aCList->push_back(5);
	aCList->push_front(2);
	aCList->push_front(1);
	aCList->push_front(0);
	std::cout << "cout my list (push back, back, push front, front): " << *aCList << std::endl;
	std::cout << "size of the list (expected 6): " << aCList->list_size() << std::endl;

	delete aCList;
	std::cout << "Test case 2 END: push front/back\n==========\n" << std::endl;


	/*
	 * TEST 3
	 * */

	std::cout << "Test case 3: init via array." << std::endl;

	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;

	aCList = new List(testArray, 10);
	List *aCList2 = new List(testArray, 10);
	aCList->push_back(11);
	aCList->push_back(12);
	std::cout << "List::alive_node_count() (expected 22): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 2): " << List::created_list_count() << std::endl;
	std::cout << "cout my list: " << *aCList << std::endl;
	std::cout << "cout my list2: " << *aCList2 << std::endl;
	std::cout << "Test case 3 END: init via array\n==========\n" << std::endl;


	/*
	 * TEST 4
	 * */

	std::cout << "Test case 4: pop front/back." << std::endl;
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	std::cout << "pop_front() half of list, cout my list (should be from 7-12): " << *aCList << std::endl;
	std::cout << "size of the list (expected 6): " << aCList->list_size() << std::endl;
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();
	aCList->pop_front();//extra pop
	std::cout << "pop_front() the rest of list, cout my list (empty): " << *aCList << std::endl;
	std::cout << "size of the list (expected 0): " << aCList->list_size() << std::endl;
	std::cout << "List::alive_node_count() (expected 10): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 2): " << List::created_list_count() << std::endl;

	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();

	std::cout << "\n\npop_back() half of list. cout my list2 (1-5): [" << *aCList2 << "]"<< std::endl;
	std::cout << "size of the list2 (expected 5): " << aCList2->list_size() << std::endl;
	std::cout << "List::alive_node_count() (expected 5): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 2): " << List::created_list_count() << std::endl;

	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();
	aCList2->pop_back();//extra pop.
	std::cout << "\n\npop_back() rest of list. cout my list2 (empty): [" << *aCList2 << "]"<< std::endl;
	std::cout << "size of the list2 (expected 0): " << aCList2->list_size() << std::endl;
	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 2): " << List::created_list_count() << std::endl;
	std::cout << "Test case 4 END: pop front/back\n==========\n" << std::endl;

	/*
	 * TEST 5
	 * */

	std::cout << "Test case 5: push front/back after pop front/back." << std::endl;
	aCList->push_front(2);
	aCList->push_front(1);
	aCList->push_front(0);
	std::cout << "cout my list (0,1,2): " << *aCList << std::endl;
	aCList2->push_back(1);
	aCList2->push_back(2);
	aCList2->push_back(3);
	std::cout << "cout my list2 (1,2,3): " << *aCList2 << std::endl;
	std::cout << "Test case 5 END: push front/back after pop front/back\n==========\n" << std::endl;

	delete aCList;
	delete aCList2;
	std::cout << "Lists cleaned up. " << std::endl;
	std::cout << "List::alive_node_count() (expected 0): " << List::alive_node_count() << std::endl;
	std::cout << "List::created_list_count() (expected 0): " << List::created_list_count() << std::endl;

	return 0;
}
