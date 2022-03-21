/*********************************************************************
 * List.h
 * Lists of integers.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include "IntList.h"

// the NULL pointer
#define NULL (0)

/*********************************************************************
 * IntNode
 * A node holding an integer value and a link to another node.
 ********************************************************************/
class IntList::IntNode
{
  friend class IntList;       // lists may access node contents
private:
	int value;                  // the value carried by the node
	IntNode* next;              // the link to the next node
	IntNode(int v, IntNode *n): // a node with value v and link to node n
		value(v), next(n) { }
};

/*********************************************************************
 * IntList l
 * l is the empty list.
 *
 * Output condition: l.length() == 0
 ********************************************************************/
IntList::IntList(): head(NULL), number(0) { }

/*********************************************************************
 * delete l
 * Delete all nodes in l.
 *
 * Effect: deallocates all memory occupied by l.
 ********************************************************************/
IntList::~IntList()
{
	IntNode *node = head;
	while (node != NULL) {
		IntNode *node0 = node->next;
		delete node;
		node = node0;
	}
}

/*********************************************************************
 * n = l.length()
 * n is the lenth of l.
 *
 * Output condition: n is the number of values in l.
 ********************************************************************/
int IntList::length() const {
	return number;
}

/*********************************************************************
 * l = l.insert(e)
 * Inserts e in l.
 *
 * Effect: inserts e at the front of l i.e. l.get(0) = e.
 * Output condition: returns a reference to this list.
 ********************************************************************/
IntList& IntList::insert(int e) {
	IntNode* node = new IntNode(e, head);
	head = node;
	number = number+1;
	return *this;
}

/*********************************************************************
 * e = l.get(i)
 * e is the value of l at position i.
 *
 * Input condition: 0 <= i < l.length()
 *
 * Output condition: e is the value of l at position i
 * (the first value of l has position 0).
 ********************************************************************/
int IntList::get(int i) const {
	IntNode *node = head;
	for (int j=0; j<number-i-1; j++)
		node = node->next;
	return node->value;
}



