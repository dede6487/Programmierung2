#include"DistPoly.h"
#include<string>

string vars[2] = { "x","y" };

DistPoly p(2, vars);

int main() {

	int e1[2] = { 1,2 };
	int coeff = 4;

	p.println();
	//DistPoly q = p.add(coeff, e1);
	//q.println();

	return 0;
}




