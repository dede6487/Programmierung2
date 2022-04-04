//**********************************************************
//File "Auxiliary.cpp"
//
// defines auxiliary functions for use in the "Atoms" project
// that are declared in "Auxiliary.h"
// 
// created by Felix Dreﬂler, 04.04.2022
//**********************************************************
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Auxiliary.h"

void toPolar(double x, double y, double& r, double& a)
{
	a = atan2(y, x);
	r = sqrt(x * x + y * y);
}

void toCartesian(double r, double a, double& x, double& y)
{
	x = r * cos(a);
	y = r * sin(a);
}
