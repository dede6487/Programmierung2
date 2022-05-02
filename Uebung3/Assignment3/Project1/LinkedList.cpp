#include "LinkedList.h"

class LinkedList::IntNode {
	friend class LinkedList;
private:
	int value; IntNode* next;
	IntNode(int v, IntNode* n) :
		value(v), next(n) { }
}

LinkedList::LinkedList() :
	head(0), number(0) { }

LinkedList::~LinkedList() {
	IntNode* node = head;
	while (node != 0) {
		IntNode* node0 = node->next;
		delete node;
		node = node0;
	}
}int LinkedList::length() const {
	return number;
}
LinkedList& LinkedList::insert(int e) {
	IntNode* node = new IntNode(e, head);
	head = node;
	number = number + 1;
	return *this;
}
int LinkedList::get(int i) const {
	IntNode* node = head;
	for (int j = 0; j < number - i - 1; j++)
		node = node->next;
	return node->value;
}