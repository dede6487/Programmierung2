/*********************************************************************
 * Stack.h
 * A stack of integers.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef STACK_H_
#define STACK_H_

/*********************************************************************
 * Stack
 * A stack of integers.
 ********************************************************************/
class Stack
{
private:
  int number;   // number of values on the stack
  int size;     // length of the stack array
  void** stack; // array holding the stack values

  /*******************************************************************
   * resize()
   * Ensure that the stack array is not full.
   *
   * Effect: allocates a bigger array and copies the values from
   * the old array (which is subsequently deleted) to the new one.
   ******************************************************************/
  void resize()
  {
    int size0 = 2*size;
    void **stack0 = new void*[size0];
    for (int i=0; i<size; i++) stack0[i] = stack[i];
    size = size0;
    stack = stack0;
  }

public:
  /*******************************************************************
   * Stack s
   * s is the empty stack.
   *
   * Output condition: s.length() == 0
   ******************************************************************/
  Stack(): number(0), size(10), stack(new void*[size]) { }

  /*******************************************************************
   * l = s.length();
   * l is the length of the stack
   *
   * Output condition: l is the number of elements on the stack
   ******************************************************************/
  int length() { return number; }

  /*******************************************************************
   * s.push(e)
   * pushes e on the stack.
   *
   * Output condition: e == l.top() and
   *                   l.length() = 1+old(l.length()) and
   *                   all other stack elements remain unchanged.
   ******************************************************************/
  void push(void *e)
  {
    if (number == size) resize();
    stack[number] = e;
    number = number+1;
  }

  /*******************************************************************
   * e = s.pop()
   * removes value at the top of s and stores it in e
   *
   * Input condition. s.length() > 0
   * Output condition: e == old(s.top()) and
   *                   s.length() == old(s.length()) - 1 and
   *                   all other stack elements remain unchanged.
   ******************************************************************/
  void *pop() { number = number-1; return stack[number]; }

  /*******************************************************************
   * e = s.top()
   * e is the value at the top of s
   *
   * Input condition. s.length() > 0
   * Output condition: e == s.top() and s remains unchanged.
   ******************************************************************/
  void *top() { return stack[number-1]; }
};

#endif /* STACK_H_ */
