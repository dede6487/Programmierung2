#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
  Stack s;
  int i = 1;
  s.push(&i);
  int *j = reinterpret_cast<int *>(s.pop());
  cout << *j;
}
