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
