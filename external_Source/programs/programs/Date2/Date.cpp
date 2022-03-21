/*
 * Date.cpp
 *
 *  Created on: 28.12.2008
 *      Author: schreine
 */
#include <iostream>
#include "Date.h"

Date :: Date() {
  day = 1;
  month = "January";
}

Date::Date(int d, char *m): day(d), month(m) { }

Date::Date(const Date &date):
day(date.day), month(date.month) { }

void Date::print() {
  std::cout << day << " " << month;
}

void Date::set(int d, char* m) {
  day = d; month = m;
}

int Date::getDay() const { return day; }

char* Date::getMonth() const { return month; }

void Date::nextDay() {
  int d = getDay();
  char* m = getMonth();
  set(d+1, m); // stupid, of course
}

void Date::copyDay(Date date) {
  int d = date.getDay();
  char* m = getMonth();
  set(d, m);
}
