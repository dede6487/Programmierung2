#pragma once

#include<string>

template<class Ring> class RecPoly
{
private:
	Ring** coeff;
	int n;
	string var;

public:
	// polynomial with n>=0 coefficients and given variable name
	RecPoly(string var, int n, Ring** coeffs);
	// copy constructor, copy assignment operator, destructor
	RecPoly(RecPoly& p);
	RecPoly& operator=(RecPoly& p);
	~RecPoly();

	//virtual functions from Ring:

	// a heap-allocated duplicate of this element
	Ring* clone();

	// the string representation of this element
	string str();

	// the constant of the type of this element and the inverse of this element
	Ring* zero();
	Ring* operator-();

	// sum and product of this element and c
	Ring* operator+(Ring* c);
	Ring* operator*(Ring* c);

	// comparison function
	bool operator==(Ring* c);
};