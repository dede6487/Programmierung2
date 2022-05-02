#pragma once

class LinkedList
{
	class IntNode;
private:
	IntNode* head;
	int number;
public:
	LinkedList();
	~LinkedList();
	int length() const;
	LinkedList& insert(int e);
	int get(int i) const;
};
