//**********************************************************
//File "Auxiliary.cpp"
//
// defines auxiliary functions for use in the "Atoms" project
// that are declared in "Auxiliary.h"
// 
// created by Felix Dressler, 04.04.2022
//**********************************************************
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Auxiliary.h"

//**********************************************************
// Funtion "toPolar"
// 
//calculates radius rand angle a of a vector using its Cartesian coordinates
//**********************************************************

void toPolar(double x, double y, double& r, double& a)
{
	a = atan2(y, x);
	r = sqrt(x * x + y * y);
}

//**********************************************************
// Funtion "toCaresian"
// 
//calculates the Cartesian coordinates of a vector using its Polar-form
//**********************************************************

void toCartesian(double r, double a, double& x, double& y)
{
	x = r * cos(a);
	y = r * sin(a);
}

//**********************************************************
// Funtion "random"
// 
// This function gives a random number inbetween given limits
// 
// input: two int numbers which define the lower and the upper
// limits of the outputted random number
// 
// output: a random number in between the given limits
// including the limits
//**********************************************************

int random(int llimit, int ulimit) {

	return ((rand()+rand()*(RAND_MAX+1)) % (ulimit - llimit + 1)) + llimit;
}
