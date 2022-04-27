#include"DistPoly.h"
#include<string>

string vars2[2] = { "x","y" };
string vars3[3] = { "x","y","z" };

int main() {

	// some exponent vectors("power products")
	int e1[3] = { 1,2,3 }; 
	int e2[2] = { 2,1 };


	// construct zero polynomial in three variables, then add monomials
	DistPoly p(3, vars3);
	p.add(3, e1);

	DistPoly q(2, vars2);
	q.add(5, e2);

	//add to polynomials whose vars do not match
	p.add(q);

	p.println();

	return 0;
}




