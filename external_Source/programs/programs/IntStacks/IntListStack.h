/*********************************************************************
 * IntListStack.h
 * Stacks of integer values implemented as lists.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef INTLISTSTACK_H_
#define INTLISTSTACK_H_

#include "IntStack.h"

/*********************************************************************
 * IntListStack
 * An implementation of IntStack by a linked list.
 ********************************************************************/
class IntListStack: public IntStack
{
  class IntNode;            // hidden node type
  IntNode *head;            // link to first node in list
public:
  IntListStack();           // the empty stack
  virtual ~IntListStack();  // deallocation of resources
  virtual bool isEmpty();   // the empty stack
  virtual void push(int e); // push e on top of stack
  virtual int pop();        // remove top of stack and return it
  virtual int top();        // return top of stack without removing it
};

#endif /* INTLISTSTACK_H_ */
