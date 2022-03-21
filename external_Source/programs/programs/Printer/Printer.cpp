/*
 * Printer.cpp
 *
 *  Created on: 22.01.2009
 *      Author: schreine
 */

#include "Printer.h"
#include <iostream>

using namespace std;

void Printer::print(int n)
{
  for(int i=0; i<n; i++)
  {
    cout << getText() << "\n";
  }
}

class IntPrinter: public Printer
{
  int i;
  char text[20];
public:
  IntPrinter(int i);
  virtual char* getText();
};

IntPrinter::IntPrinter(int i)
{
  this->i = i;
}

char* IntPrinter::getText()
{
  sprintf(text, "%d", i);
  return text;
}

int main()
{
  IntPrinter p(7);
  p.print(3);
}
