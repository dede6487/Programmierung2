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
//tests from the assignment
    Ring* c[] = { new Integer(-5), new Integer(2), new Integer(0), new Integer(-3) };

    RecPoly* p = new RecPoly("x", 4, c); // p = -3x^3 + 2x - 5
    cout << p->str() << endl;

    RecPoly* q = // q = p+p = -6x^3 + 4x - 10
        dynamic_cast<RecPoly*>(p->operator+(p));
    cout << q->str() << endl;

    RecPoly* r = // r = p*q = 50 - 40 x + 8 x^2 + 60 x^3 - 24 x^4 + 18 x^6
        dynamic_cast<RecPoly*>(p->operator*(q));
    cout << r->str() << endl;

//additional tests
    
//zero

    RecPoly* z = //zero polynomial
        dynamic_cast<RecPoly*>(p->zero());
    cout << z->str() << endl;

    RecPoly* z2 = // = p + 0
        dynamic_cast<RecPoly*>(p->operator+(z));
    cout << z2->str() << endl;

    RecPoly* z3 = // = p * 0
        dynamic_cast<RecPoly*>(p->operator*(z));
    cout << z3->str() << endl;

//negation

    RecPoly* g = //= -p
        dynamic_cast<RecPoly*>(p->operator-());
    cout << g->str() << endl;

    RecPoly* g2 = // = -p + p = 0
        dynamic_cast<RecPoly*>(g->operator+(p));
    cout << g2->str() << endl;

//multivariate polynomials

    Ring* k[] = { dynamic_cast<Ring*>(p),dynamic_cast<Ring*>(q)};
    Ring* l[] = { dynamic_cast<Ring*>(p) };

    RecPoly* s = new RecPoly("y", 2, k);
    cout << s->str() << endl;

    RecPoly* s2 = new RecPoly("y", 1, l);
    cout << s2->str() << endl;

    RecPoly* s3 = // s2 + s
        dynamic_cast<RecPoly*>(s2->operator+(s));
    cout << s3->str() << endl;

    RecPoly* s4 = //s2*s
        dynamic_cast<RecPoly*>(s2->operator*(s));
    cout << s4->str() << endl;

    return 0;
}