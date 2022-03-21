/*
 * DateMain.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

 class Date {
    public:                    // access specifier
      int day;
      char *month;
  };

int main()
{
  Date date;                   // an object
  date.day = 24;
  date.month = "December";

  Date *dptr = new Date;       // a pointer to an object
  dptr->day = 1;
  dptr->month = "January";
  delete dptr;
}
