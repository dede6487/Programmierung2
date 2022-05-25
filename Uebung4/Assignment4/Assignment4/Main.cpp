//******************************************************************
// "Main.cpp"
//
// is used to test the functions of Ring and its subclasses.
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

#include "Integer.h"
#include "RecPoly.h"
#include <iostream>

using namespace std;

int main() {
	Ring* c[] = { new Integer(-5), new Integer(2), new Integer(0), new Integer(-3) };

	RecPoly* p = new RecPoly("x", 4, c); // p = -3x^3 + 2x - 5

	cout << p->str() << endl;

	RecPoly* q = // q = p+p = -6x^3 + 4x - 10
		dynamic_cast<RecPoly*>(p->operator+(p));
		cout << q->str() << endl;
	RecPoly* r = // r = p*q = 50 - 40 x + 8 x^2 + 60 x^3 - 24 x^4 + 18 x^6
		dynamic_cast<RecPoly*>(p->operator*(q));
	cout << r->str() << endl;



	return 0;
}