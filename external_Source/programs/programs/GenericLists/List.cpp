/*********************************************************************
 * List.h
 * Generic Lists
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include "List.h"

/********************************************************************
 * out << l
 * Prints values of l on out.
 *
 * Effect: l is printed in the format "(val1, val2, ..., valn)".
 *******************************************************************/
template<typename T> ostream& operator<<(ostream& out, List<T>& l)
{
  Node<T> *node = l.head;
  out << "(";
  while (node != NULL)
  {
    out << node->value;
    node = node->next;
    if (node != NULL) out << ", ";
  }
  out << ")";
  return out;
}

/********************************************************************
 * reset()
 * Resets list to the empty state.
 *
 * Effect: deallocates all nodes and resets data members.
 *******************************************************************/
template<typename T> void List<T>::reset()
{
  Node<T> *node = head;
  while (node != NULL)
  {
    Node<T> *prev = node;
    node = node->next;
    delete prev;
  }
  head = NULL;
  len = 0;
}

/********************************************************************
 * copy(l)
 * Copies values of l to this list.
 *
 * Input condition: this list must be empty.
 * Effect: creates a duplicate of l in this list.
 *******************************************************************/
template<typename T> void List<T>::copy(List& l)
{
  Node<T> *prev = NULL;
  int n = l.length();
  Node<T> *node = l.head;
  for (int i=0; i<n; i++)
  {
    Node<T> *node0 = new Node<T>(node->value, NULL);
    if (prev == NULL)
      head = node0;
    else
      prev->next = node0;
    prev = node0;
    node = node->next;
  }
  len = n;
}

/********************************************************************
 * List l
 * l is the empty list.
 *
 * Effect: constructs the list without values.
 *******************************************************************/
template<typename T> List<T>::List(): head(NULL), len(0) { }

/********************************************************************
 * delete l
 * Deallocates all nodes of l.
 *
 * Effect: the memory allocated for this list is deallocated.
 *******************************************************************/
template<typename T> List<T>::~List() { reset(); }

/********************************************************************
 * r(l)
 * r is a copy of l.
 *
 * Effect: nodes are allocated to hold all values of l in r.
 *******************************************************************/
template<typename T> List<T>::List(List& l) { copy(l); }

/********************************************************************
 * r = l
 * r is a copy of l.
 *
 * Effect: the existing nodes of r are deallocated and new nodes
 * are allocated to hold all values of l in r.
 *******************************************************************/
template<typename T> List<T>& List<T>::operator=(List& l)
{
  reset();
  copy(l);
  return l;
}

/********************************************************************
 * n = l.length()
 * n is the length of l.
 *
 * Output condition: n becomes the number of values in l.
 *******************************************************************/
template<typename T> int List<T>::length()
{
  return len;
}

/********************************************************************
 * v = l[i]
 * v is the i-th value of l.
 *
 * l[i] = v
 * the i-th value of l is set to v.
 *
 * Input condition: 0 <= i < l.length()
 *
 * Output condition: returns a reference to the value at position i
 * which can be used for reading and writing (position 0 denotes
 * the first value of l).
 *
 * Time complexity: O(i) (linear in the position).
 *******************************************************************/
template<typename T> T& List<T>::operator[](int i)
{
  Node<T> *node = head;
  for (int j=0; j<i; j++)
    node = node->next;
  return node->value;
}

/********************************************************************
 * l = l.insert(i, v)
 * Value v is inserted into l at position i.
 *
 * Input condition: 0 <= i <= l.length()
 * Effect: inserts v into l such that l[i] = v.
 * Output condition: returns a reference to l.
 * Time complexity: O(i) (linear in the position).
 *******************************************************************/
template<typename T> List<T>& List<T>::insert(int i, T value)
{
   Node<T> *prev = NULL;
   Node<T> *next = head;
   for (int j=0; j<i; j++)
   {
     prev = next;
     next = next->next;
   }
   Node<T> *node = new Node<T>(value, next);
   if (prev == NULL)
     head = node;
   else
     prev->next = node;
   len = len+1;
   return *this;
}

/********************************************************************
 * l = l.remove(i)
 * The value at position i is removed from l.
 *
 * Input condition: 0 <= i < l.length()
 *
 * Effect: removes l[i] from l i.e.
 *
 *         l.length() = old(l.length())-1 and
 *         l[j] = old(l[j]) for 0 <= j < i and
 *         l[j] = old(l[j+1]) for i <= j < length(l)
 *
 * Output condition: returns a reference to l.
 * Time complexity: O(i) (linear in the position).
 *******************************************************************/
template<typename T> List<T>& List<T>::remove(int i)
{
   Node<T> *prev = NULL;
   Node<T> *next = head;
   for (int j=0; j<i; j++)
   {
     prev = next;
     next = next->next;
   }
   if (prev == NULL)
     head = next->next;
   else
     prev->next = next->next;
   len = len-1;
   delete next;
   return *this;
}

