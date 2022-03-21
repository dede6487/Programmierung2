/*
 * DateMain.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

#include "Date.h"

int main(int argc, char* argv[]) {
  Date::thisMonth = "February";
  Date* d = Date::create();
  Date::print(d);
  return 0;
}
