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

  Date();
  Date(int d, char *m);
  Date(const Date &date);

  void print();
  void set(int d, char* m);
  int getDay() const;
  char* getMonth() const;

  void nextDay();
  void copyDay(Date date);

};


#endif /* DATE_H_ */
