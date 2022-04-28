//******************************************************************
// "DistPoly.h"
// 
// is the header, that defines the DistPoly class.
//
// created by Felix Dressler, 28.04.2022
//******************************************************************
#pragma once

#include<string>

using namespace std;

//******************************************************************
// class "DistPoly"
// 
// this class represents polynomials by arrays of monomials and provides
// a number of operations with these polynomials.
// 
// Monom ... class that defines monomials
// n ... number of variables
// vars ... names of the variables
// monoms ... array of Monoms
// m ... number of potential monoms in this polynomial
// am ... actual number of monoms in this polynomial -1
// 
// The member functions are shortly describes directly in the class.
// For further documentation see the "DistPoly.h" file
//******************************************************************

class DistPoly
{
private:
	class Monom; 
	int n; 
	string* vars;
	Monom* monoms; 
	int m; 
	int am; 

	//enlarges the polynomial by a given factor greater than or equal two
	void resize(int factor);

	//gives back the position in which the monom with the exponents exps should be inserted
	int sort(int* exps, int n, int j);

public:

	//constructor
	DistPoly(int n, string* vars);

	//copy constructor, copy assignment operator, destructor
	DistPoly(DistPoly& p);
	DistPoly& operator=(DistPoly& p);
	~DistPoly();

	//adds monomials to a polynomial
	DistPoly& add(int coeff, int* exps);

	//adds polynomials to polynomials
	DistPoly& add(DistPoly& p);

	//prints a polynomial
	void println();
};

