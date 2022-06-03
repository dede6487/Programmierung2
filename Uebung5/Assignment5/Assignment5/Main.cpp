//******************************************************************
// "Main.cpp"
//
// is used to test the functions of the template class RecPoly.
// 
// created by: Felix Dressler - 03.06.2022
//******************************************************************

#include "Integer.h"
#include "RecPoly.h"
#include <iostream>

using namespace std;

int main() {
    //tests from the assignment
    Integer* c[] = { new Integer(-5), new Integer(2), new Integer(0), new Integer(-3) };

    UniPoly* p = new UniPoly("x", 4, c); // p = -3x^3 + 2x - 5
    cout << p->str() << endl;

    UniPoly* q = // q = p+p = -6x^3 + 4x - 10
        p->operator+(p);
    cout << q->str() << endl;

    UniPoly* r = // r = p*q = 50 - 40 x + 8 x^2 + 60 x^3 - 24 x^4 + 18 x^6
        p->operator*(q);
    cout << r->str() << endl;

    //additional tests

    //zero

    UniPoly* z = //zero polynomial
        p->zero();
    cout << z->str() << endl;

    UniPoly* z2 = // = p + 0
        p->operator+(z);
    cout << z2->str() << endl;

    UniPoly* z3 = // = p * 0
        p->operator*(z);
    cout << z3->str() << endl;

    //negation

    UniPoly* g = //= -p
        p->operator-();
    cout << g->str() << endl;

    UniPoly* g2 = // = -p + p = 0
        g->operator+(p);
    cout << g2->str() << endl;

    //multivariate polynomials

    UniPoly* k[] = { p,q };
    UniPoly* l[] = { p };

    BiPoly* s = new BiPoly("y", 2, k);
    cout << s->str() << endl;

    BiPoly* s2 = new BiPoly("y", 1, l);
    cout << s2->str() << endl;

    BiPoly* s3 = // s2 + s
        s2->operator+(s);
    cout << s3->str() << endl;

    BiPoly* s4 = //s2*s
        s2->operator*(s);
    cout << s4->str() << endl;

    return 0;
}