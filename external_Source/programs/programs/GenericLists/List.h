/*********************************************************************
 * List.h
 * Generic Lists
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef LIST_H_
#define LIST_H_

#include <ostream>

using namespace std;

// the generic class
template<typename T> class List;

// the operator for printing lists
template<typename T> ostream& operator <<(ostream& out, List<T>& l);

/*********************************************************************
 * Node<T>
 * A node holding a value of type T.
 ********************************************************************/
template<typename T> class Node
{
  T value;    // the value
  Node* next; // pointer to next node
public:
  // a node holding value v and linked to next node n
  Node(T& v, Node* n): value(v), next(n) { }

  // List and print operator may access private data
  friend class List<T>;

  friend ostream& operator<< <T>(ostream& out, List <T> &l);
};

/*********************************************************************
 * List<T>
 * A list holding values of type T.
 ********************************************************************/
template<typename T> class List
{
  Node<T> *head;        // pointer to first node in list
  int len;              // the number of nodes in the list
  void reset();         // reset list to empty state
  void copy(List &l);   // copy values from l to this list
public:
  List();                          // the empty list
  ~List();                         // deallocation of nodes
  List(List& l);                   // copy values of l
  List& operator=(List& l);        // assign values from l
  int length();                    // number of values
  T& operator[](int i);            // value at position i
  List<T>& insert(int i, T value); // insert value at i
  List<T>& remove(int i);          // remove value from i

  friend ostream& operator<< <T>(ostream& out, List <T>& l);
};

// template implementation
#include "List.cpp"

#endif /* LIST_H_ */
