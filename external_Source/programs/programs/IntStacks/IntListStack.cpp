/*
 * ListIntStack.cpp
 *
 *  Created on: 18.01.2009
 *      Author: schreine
 */

#include "IntListStack.h"
#define NULL (0)

/********************************************************
 * IntListStack::IntNode
 * A node holding an integer and a link to another node.
 *******************************************************/
class IntListStack::IntNode
{
public:
  int value;     // the value
  IntNode* next; // the link to the next node

  // a node with value v and link n to next node
  IntNode(int v, IntNode *n): value(v), next(n) { }
};

/********************************************************
 * IntListStack l
 * l is the empty stack
 *
 * Output condition: l.isEmpty()
 *******************************************************/
IntListStack::IntListStack() {
  head = NULL;
}

/********************************************************
 * delete l
 * delete resources held by l
 *
 * Effect: all nodes referenced by l are deallocated.
 *******************************************************/
IntListStack::~IntListStack() {
  while (head != NULL) pop();
}

/********************************************************
 * b = l.isEmpty()
 * b indicates whether l is the empty stack
 *
 * Output condition: b is true if and only if
 * there are no values on the stack.
 *******************************************************/
bool IntListStack::isEmpty() {
  return head == NULL;
}

/********************************************************
 * l.push(e)
 * push e on top of stack.
 *
 * Output condition: l.top() == e
 *******************************************************/
void IntListStack::push(int e) {
  head = new IntNode(e, head);
}

/********************************************************
 * e = l.pop()
 * pop e from top of stack.
 *
 * Input condition: !l.isEmpty()
 * Output condition: e = old(l.top())
 * Effect: e is removed from the stack.
 *******************************************************/
int IntListStack::pop() {
  int result = head->value;
  IntNode *next = head->next;
  delete head;
  head = next;
  return result;
}

/********************************************************
 * e = l.top()
 * e is the value at the top of stack.
 *
 * Input condition: !l.isEmpty()
 * Output condition: e = l.top()
 * Effect: none (l remains unchanged)
 *******************************************************/
int IntListStack::top() {
  return head->value;
}
