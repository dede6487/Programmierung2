//******************************************************************
// "Integer.h
//
//
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

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
