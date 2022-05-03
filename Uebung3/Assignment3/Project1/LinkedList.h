//******************************************************************
// "LinkedList.h"
// 
// contains the class "LinkedList", that implements a linked list
// based on the linked list that was presented in the lecture slides.
// 
// created by Felix Dressler, 
//******************************************************************

#pragma once

class LinkedList
{
	class Node;
private:
	Node* head;
	int number;
public:
	LinkedList();
	~LinkedList();
	int length() const;
	LinkedList& insert(int* e);
	int* get(int i) const;
};
