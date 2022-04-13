#pragma once

#include"DistPoly.cpp"

#include<string>

using namespace std;

class DistPoly
{
private:
	int n;
	string* vars;
	int coeff;
	int exps;
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

