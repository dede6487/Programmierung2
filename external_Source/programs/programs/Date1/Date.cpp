/*
 * Date.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

#include <iostream>
#include "Date.h"


// definitions of static data members
const int Date::thisDay;
char* Date::thisMonth = "January";

// definitions of static member functions
void Date::print(Date *date) {
  std::cout << date->day << "/" << date->month;
}


