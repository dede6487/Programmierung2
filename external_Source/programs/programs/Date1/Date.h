/*
 * Date.h
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:                    // access specifier
  int day;
  char *month;

  // data members
  static const int thisDay = 1;
  static char* thisMonth;

  // member functions
  static Date* create() {
    Date* d = new Date;
    d->day = thisDay;
    d->month = thisMonth;
    return d;
  }

  static void print(Date *date);
};

#endif /* DATE_H_ */
