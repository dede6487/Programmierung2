/*
 * DateMain.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

#include "Date.h"

int main()
{
  Date date(28, "February");
  date.nextDay();
  date.print();
  Date date1(28, "February");
  Date date2(15, "March");
  date1.copyDay(date2);
  date1.print();
  return 0;
}
