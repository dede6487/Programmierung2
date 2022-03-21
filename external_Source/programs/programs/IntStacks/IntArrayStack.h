/*********************************************************************
 * IntArrayStack.h
 * Stacks of integer values implemented as arrays.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef INTARRAYSTACK_H_
#define INTARRAYSTACK_H_

#include "IntStack.h"

/*********************************************************************
 * IntArrayStack
 * An implementation of IntStack by a dynamically resized array.
 ********************************************************************/
class IntArrayStack : public IntStack
{
private:
  int number;  // the number of elements on the stack
  int size;    // the size of the array
  int* stack;  // a pointer to the array of the denoted size

  /*********************************************************************
   * resize()
   * Ensure that allocated array is not full.
   *
   * Effect: allocates a bigger array into which the elements are copied
   * (the original area is deleted).
   ********************************************************************/
  void resize()
  {
    int size0 = 2*size;
    int *stack0 = new int[size0];
    for (int i=0; i<size; i++) stack0[i] = stack[i];
    delete[] stack;
    size = size0;
    stack = stack0;
  }

public:

  /********************************************************
   * IntListStack l
   * l is the empty stack
   *
   * Output condition: l.isEmpty()
   *******************************************************/
  IntArrayStack(): number(0), size(10), stack(new int[size]) { }

  /********************************************************
   * delete l
   * delete resources held by l
   *
   * Effect: all nodes referenced by l are deallocated.
   *******************************************************/
  virtual ~IntArrayStack() { delete[] stack; }

  /********************************************************
   * n = l.length()
   * n is the length of the stack.
   *
   * Output condition: n is the number of elements that
   * were pushed on the stack and not yet popped from it.
   *******************************************************/
  int length() { return number; }

  /********************************************************
   * b = l.isEmpty()
   * b indicates whether l is the empty stack
   *
   * Output condition: b is true if and only if
   * there are no values on the stack.
   *******************************************************/
  virtual bool isEmpty()
  {
    return length() == 0;
  }

  /********************************************************
   * l.push(e)
   * push e on top of stack.
   *
   * Output condition: l.top() == e
   *******************************************************/
  virtual void push(int e)
  {
    if (number == size) resize();
    stack[number] = e;
    number = number+1;
  }

  /********************************************************
   * e = l.pop()
   * pop e from top of stack.
   *
   * Input condition: !l.isEmpty()
   * Output condition: e = old(l.top())
   * Effect: e is removed from the stack.
   *******************************************************/
  virtual int pop() { number = number-1; return stack[number]; }

  /********************************************************
   * e = l.top()
   * e is the value at the top of stack.
   *
   * Input condition: !l.isEmpty()
   * Output condition: e = l.top()
   * Effect: none (l remains unchanged)
   *******************************************************/
  virtual int top() { return stack[number-1]; }
};

#endif /* INTARRAYSTACK_H_ */
