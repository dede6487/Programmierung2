/*********************************************************************
 * List.h
 * Lists of integers.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef INTLIST_H_
#define INTLIST_H_

/*********************************************************************
 * IntList
 * A list holding an arbitrary number of integer values.
 ********************************************************************/
class IntList
{
  class IntNode;           // the (hidden) type of list nodes

private:
	IntNode *head;           // pointer to first node in list
	int number;              // number of nodes in list

public:
	IntList();               // the empty list
	~IntList();              // deallocation of all list nodes
	int length() const;      // the number of values in the list
	IntList& insert(int e);  // insert e at the front of the list
	int get(int i) const;    // get value at position i
};

#endif /* INTLIST_H_ */
