#include"DistPoly.h"
#include<string>

string vars[1] = { "x" };

int main() {

	// some exponent vectors("power products")
	int e1[1] = { 1 }; int e2[1] = { 2 }; int e3[1] = { 1 };
	int e4[1] = { 0 }; int e5[1] = { 0 }; int e6[1] = { 2 };

	// construct zero polynomial in two variables, then add monomials
	DistPoly p(1, vars);
	p.add(3, e1).add(5, e2).add(7, e3).add(11, e4).add(13, e5);

	// construct zero polynomial in two variables, then add monomials
	DistPoly q(1, vars);
	q.add(11, e4).add(-3, e2).add(2, e6).add(-2, e2);

	// print p and q
	p.println();
	q.println();

	// set p to p+2*q and print it

	DistPoly r = p;
	r.add(q).add(q);
	p = r;
	p.println();

	return 0;
}




