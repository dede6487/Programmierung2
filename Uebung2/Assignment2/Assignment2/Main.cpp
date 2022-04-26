#include"DistPoly.h"
#include<string>

string vars[2] = { "x","y" };

int main() {

	// some exponent vectors("power products")
	int e1[2] = { 1,2 }; int e2[2] = { 2,1 }; int e3[2] = { 1,0 };
	int e4[2] = { 0,1 }; int e5[2] = { 0,0 }; int e6[2] = { 2,2 };

	// construct zero polynomial in two variables, then add monomials
	string vars[2] = { "x","y" };
	DistPoly p(2, vars);
	p.add(3, e1).add(5, e2).add(7, e3).add(11, e4).add(13, e5);

	// construct zero polynomial in two variables, then add monomials
	DistPoly q(2, vars);
	q.add(11, e4).add(-3, e2).add(2, e6).add(-2, e2);

	// print p and q
	p.println();
	q.println();

	// set p to p+2*q and print it

	DistPoly r = p;
	r.add(3,e1).add(-1, e2);
	p = r;
	p.println();

	return 0;
}




