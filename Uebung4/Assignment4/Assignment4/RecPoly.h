#pragma once
#include"Ring.h"

class RecPoly : public Ring {
public:
	// polynomial with n>=0 coefficients and given variable name
	RecPoly(string var, int n, Ring** coeffs);
	// copy constructor, copy assignment operator, destructor
	RecPoly(RecPoly& p);
	RecPoly& operator=(RecPoly& p);
	virtual ~RecPoly();
};
