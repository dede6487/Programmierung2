#pragma once
#include"Ring.h"

class Integer : public Ring {
private:
	int n;
public:
	// integer with value n (default 0)
	Integer(int n = 0);

	// destructor
	virtual ~Integer() {

	}
	
	// a heap-allocated duplicate of this element
	virtual Integer* clone() = 0;

	// the string representation of this element
	virtual string str() = 0;

	// the constant of the type of this element and the inverse of this element
	virtual Integer* zero() = 0;
	virtual Integer* operator-() = 0;

	// sum and product of this element and c
	virtual Integer* operator+(Integer* c) = 0;
	virtual Integer* operator*(Integer* c) = 0;

	// comparison function
	virtual bool operator==(Integer* c) = 0;
};
