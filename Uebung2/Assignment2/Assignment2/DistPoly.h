#pragma once

#include<string>

using namespace std;

class Monom 
{
public:
	int coeff;
	int* exps;

	//Monom(int coeff, int* exps);

};

class DistPoly
{
private:
	int n; //number of variables
	string* vars;
	Monom* monoms;
	int m; //number of potential monoms in this polynomial (allocated memory)
	int am; //actual number of monoms in this polynomial
public:

	//constructor
	DistPoly(int n, string* vars);

	//copy constructor, copy assignment operator, destructor
	DistPoly(DistPoly& p);
	DistPoly& operator=(DistPoly& p);
	~DistPoly();

	DistPoly& add(int coeff, int* exps);
	DistPoly& add(DistPoly& p);
	void println_brkts(); //prints the polynomial in brackets-style
	void println();

	void resize(int factor, int m);//enlarges the polynomial, 

	int sort(DistPoly& p, int* exps);//gives back the position in which the monom with the exponents exps should be inserted
};

