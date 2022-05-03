#include "LinkedList.h"

class LinkedList::Node {
	friend class LinkedList;
private:
	int* value; Node* next;
	Node(int* v, Node* n){ 
		next = n;
		value = new int[2];
			value[0] = v[0];
			value[1] = v[1];
	}
}

LinkedList::LinkedList() {
	head = 0;
	number = 0;
}

LinkedList::~LinkedList() {
	Node* node = head;
	while (node != 0) {
		Node* node0 = node->next;
		delete node;
		node = node0;
	}
}

int LinkedList::length() const {
	return number;
}
LinkedList& LinkedList::insert(int* e) {
	Node* node = new Node(e, head);
	head = node;
	number = number + 1;
	return *this;
}
int* LinkedList::get(int i) const {
	Node* node = head;
	for (int j = 0; j < number - i - 1; j++)
		node = node->next;
	return node->value;
}
