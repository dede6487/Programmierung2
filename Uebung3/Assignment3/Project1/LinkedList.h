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
