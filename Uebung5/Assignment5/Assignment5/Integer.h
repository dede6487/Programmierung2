//******************************************************************
// "Integer.h"
//
// contains the class Integer and its function deklarations.
// 
// created by: Felix Dressler - 03.06.2022
//******************************************************************

#pragma once

#include<string>
#include<iostream>

using namespace std;

class Integer {
private:
	int n;
public:
	// integer with value n (default 0)
	Integer(int n = 0);

	// destructor - empty because in Integer no new arrays/pointers are created
	~Integer() {

	}

	// a heap-allocated duplicate of this element
	Integer* clone();

	// the string representation of this element
	string str();

	// the constant of the type of this element and the inverse of this element
	Integer* zero();
	Integer* operator-();

	// sum and product of this element and c
	Integer* operator+(Integer* c);
	Integer* operator*(Integer* c);

	// comparison function
	bool operator==(Integer* c);
};