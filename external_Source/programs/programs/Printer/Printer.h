/*
 * Printer.h
 *
 *  Created on: 22.01.2009
 *      Author: schreine
 */

#ifndef PRINTER_H_
#define PRINTER_H_

class Printer
{
public:
  Printer() { } ;
  virtual ~Printer() { };
  void print(int n);
  virtual char* getText() = 0;
};

#endif /* PRINTER_H_ */
