//******************************************************************
// "RecPoly.h"
//
//
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

#pragma once
#include"Ring.h"

class RecPoly : public Ring {
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
	virtual ~RecPoly();

	// a heap-allocated duplicate of this element
	virtual Ring* clone();

	// the string representation of this element
	virtual string str();

	// the constant of the type of this element and the inverse of this element
	virtual Ring* zero();
	virtual Ring* operator-();

	// sum and product of this element and c
	virtual Ring* operator+(Ring* c);
	virtual Ring* operator*(Ring* c);

	// comparison function
	virtual bool operator==(Ring* c);
};
