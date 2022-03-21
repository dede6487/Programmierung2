/*
 * Date.h
 *
 *  Created on: 24.11.2008
 *      Author: schreine
 */

#ifndef DATE_H_
#define DATE_H_

#include <iostream>

using namespace std;

class Date
{
  private:
	int day;
	int month;
  public:
	Date(int d, int m)
	{
	  day = d;
	  month = m;
	}
	void print()
	{
	  cout << day << "." << month << ".";
	}
	static void main()
	{
	  Date d = Date(24, 12);
	  d.print();
	}
};

#endif /* DATE_H_ */
