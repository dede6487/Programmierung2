/*
 * IntStackMain.cpp
 *
 *  Created on: 18.01.2009
 *      Author: schreine
 */

#include "IntStack.h"
#include "IntArrayStack.h"
#include "IntListStack.h"

#include <iostream>
using namespace std;

int main()
{
  IntStack* stack = new IntArrayStack();
  stack->push(1);stack->push(2);
  cout << stack->pop();
  delete stack;

  stack = new IntListStack();
  stack->push(1);stack->push(2);
  cout << stack->pop();
  delete stack;
}
