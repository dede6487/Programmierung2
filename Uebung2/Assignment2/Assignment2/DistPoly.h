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
	int n;
	string* vars;
	Monom Monom;
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

