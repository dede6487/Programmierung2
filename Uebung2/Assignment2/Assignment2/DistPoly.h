#pragma once

#include<string>

using namespace std;

class Monom 
{
public:
	int coeff;
	int* exps;
	int n;

	//constructor
	Monom(int coeff, int* exps, int n);
	Monom();

	//copy constructor, copy assignment operator, destructor
	Monom& operator=(Monom& m);

	//destructor
	//~Monom();


};

class DistPoly
{
private:
	int n; //number of variables
	string* vars; //names of the variables
	Monom* monoms; //pointer to an array of monomials
	int m; //number of potential monoms in this polynomial (allocated memory)
	int am; //actual number of monoms in this polynomial -1
public:

	//constructor
	DistPoly(int n, string* vars);

	//copy constructor, copy assignment operator, destructor
	DistPoly(DistPoly& p);
	DistPoly& operator=(DistPoly& p);
	~DistPoly();

	DistPoly& add(int coeff, int* exps);
	DistPoly& add(DistPoly& p);
	//void println_brkts(); //prints the polynomial in brackets-style
	void println();

	void resize(int factor);//enlarges the polynomial, 

	int sort(int* exps, int n, int j);//gives back the position in which the monom with the exponents exps should be inserted
};

