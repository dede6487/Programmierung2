/*********************************************************************
 * IntStack.h
 * Interface to a stack of integer values.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef INTSTACK_H_
#define INTSTACK_H_

/******************************************************************
 * IntStack
 * An interface to a stack of integer values.
 *****************************************************************/
class IntStack
{
public:
  virtual ~IntStack() { } ;         // deallocate resources
  virtual bool isEmpty() = 0;       // true if there are no values on stack
  virtual void push(int value) = 0; // push value on top of stack
  virtual int pop() = 0;            // remove top of stack and return it
  virtual int top() = 0;            // return top of stack without removing it
};

#endif /* INTSTACK_H_ */
