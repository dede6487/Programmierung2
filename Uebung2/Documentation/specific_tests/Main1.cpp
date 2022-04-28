//******************************************************************
// "Main.cpp"
// 
// is the Main cpp file that was used to test different scenarios
// of using the DistPoly class.
// 
// There are different versions of this file with different intentions
// in the assignment folder.
//
//created by Felix Dressler, 28.04.2022
//******************************************************************
#include"DistPoly.h"
#include<string>

string vars3[3] = { "x","y","z" };

int main() {

	// some exponent vectors("power products")
	int e1[3] = { 1,2,2 }; int e2[3] = { 2,1,0 }; int e3[3] = { 1,0,0 };
	int e4[3] = { 0,1,3 }; int e5[3] = { 0,0,0 }; int e6[3] = { 2,2,1 };

	// construct zero polynomial in two variables, then add monomials
	DistPoly p(3, vars3);
	p.add(3, e1).add(5, e2).add(7, e3).add(11, e4).add(13, e5);

	// construct zero polynomial in two variables, then add monomials
	DistPoly q(3, vars3);
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




