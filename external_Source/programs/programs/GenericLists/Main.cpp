/*
 * Main.cpp
 *
 *  Created on: 04.02.2009
 *      Author: schreine
 */

#include <iostream>
#include "List.h"

using namespace std;

int main()
{
  List<int> l;
  l.insert(0, 1).insert(1, 2).insert(2, 3).remove(1).insert(1, 4);
  cout << l << "\n";
  List<int> r;
  r = l;
  l[1] = 7;
  cout << l << "\n";
  cout << r << "\n";
}
