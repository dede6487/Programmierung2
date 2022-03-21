/*
 * Main.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

#include <iostream>
#include "IntList.h"

using namespace std;

int main()
{
	IntList l;
	l.insert(2).insert(3).insert(5);
	cout << l.length();  // 3
	cout << l.get(2);    // 5
	return 0;
}
