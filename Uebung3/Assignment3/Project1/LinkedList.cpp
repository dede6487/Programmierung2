//******************************************************************
// "LinkedList.h"
// 
// contains the methods of the class "LinkedList" based on the
// functionality as presented in the lecture slides.
// 
// created by Felix Dressler, 
//******************************************************************

#include "LinkedList.h"
#include"Polygon.h"

class LinkedListArr::Node {
	friend class LinkedListArr;
private:
	int* value; Node* next;
	Node(int* v, Node* n) {
		next = n;
		value = new int[2];
		value[0] = v[0];
		value[1] = v[1];
	}
};

LinkedListArr::LinkedListArr() {
	head = 0;
	number = 0;
}

LinkedListArr::~LinkedListArr() {
	Node* node = head;
	while (node != 0) {
		Node* node0 = node->next;
		delete node;
		node = node0;
	}
}

int LinkedListArr::length() const {
	return number;
}
LinkedListArr& LinkedListArr::insert(int* e) {
	Node* node = new Node(e, head);
	head = node;
	number = number + 1;
	return *this;
}
int LinkedListArr::get(int i, int n) const {
	Node* node = head;
	for (int j = 0; j < number - i - 1; j++)
		node = node->next;
	return node->value[n];
}

//*************************************************************************************************

