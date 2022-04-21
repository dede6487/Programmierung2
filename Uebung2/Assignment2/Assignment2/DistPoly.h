#pragma once

#include<string>

using namespace std;

struct Monom {
	int coeff;
	int* exps;
};

class DistPoly
{
private:
	int n; //number of variables -1
	string* vars;
	Monom* monoms;
	int m; //number of monoms in this polynomial -1
public:

	//constructor
	DistPoly(int n, string* vars);

	//copy constructor, copy assignment operator, destructor
	DistPoly(DistPoly& p);
	DistPoly& operator=(DistPoly& p);
	~DistPoly();

	DistPoly& add(int coeff, int* exps);
	DistPoly& add(DistPoly& p);
	void println();
};

