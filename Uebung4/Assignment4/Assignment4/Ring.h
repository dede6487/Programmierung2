//******************************************************************
// "Ring.h"
//
// contains the pure abstract class Ring, which defines the
// base-functionality that should be provided by a Ring.
// 
// created by: Felix Dressler - 24.05.2022
//******************************************************************

#pragma once
#include<string>

using namespace std;

class Ring {
public:
	// destructor
	virtual ~Ring() {}

	// a heap-allocated duplicate of this element
	virtual Ring* clone() = 0;

	// the string representation of this element
	virtual string str() = 0;

	// the constant of the type of this element and the inverse of this element
	virtual Ring* zero() = 0;
	virtual Ring* operator-() = 0;

	// sum and product of this element and c
	virtual Ring* operator+(Ring* c) = 0;
	virtual Ring* operator*(Ring* c) = 0;

	// comparison function
	virtual bool operator==(Ring* c) = 0;
};
