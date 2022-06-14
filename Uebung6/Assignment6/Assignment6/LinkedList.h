//******************************************************************
// "LinkedList.h"
// 
// contains the class "LinkedList", that implements a linked list
// based on the linked list that was presented in the lecture slides.
// 
// created by Felix Dressler, 
//******************************************************************

#pragma once

class LinkedListArr
{
	class Node;
private:
	Node* head;
	int number; //starts with 0 for the first element
public:
	LinkedListArr();
	~LinkedListArr();

	int length() const;
	LinkedListArr& insert(int* e);
	int get(int i, int n) const;
};
