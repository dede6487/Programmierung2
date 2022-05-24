#include "Integer.h"
#include "RecPoly.h"
#include <iostream>

using namespace std;

int main() {
	Ring* c[] = { new Integer(-5), new Integer(2), new Integer(0), new Integer(-3) };

	RecPoly* p = new RecPoly("x", 4, c); // p = -3x^3 + 2x - 5

	cout << p->str() << endl;

	RecPoly* q = //new RecPoly(*p); //= // q = p+p = -6x^3 + 4x - 10
		dynamic_cast<RecPoly*>(p->operator+(p));
		cout << q->str() << endl;
	RecPoly* r = // r = p*q
		dynamic_cast<RecPoly*>(p->operator*(q));
	cout << r->str() << endl;



	return 0;
}