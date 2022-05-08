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

class LinkedListInt
{
	class IntNode;
private:
	IntNode* head;
	int number; //starts with 0 for the first element
public:
	LinkedListInt();
	~LinkedListInt();

	int length() const;
	LinkedListInt& insert(int e);
	int get(int i) const;
};