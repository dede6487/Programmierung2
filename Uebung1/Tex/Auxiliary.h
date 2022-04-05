//**********************************************************
//Header "Auxiliary.h"
//
// declares auxiliary functions for use in the "Atoms" project
// for further elaboration of functions, see "Auxiliary.cpp"
// 
// created by Felix Dressler, 04.04.2022
//**********************************************************
#pragma once

//calculates radius r and angle a of a vector using its Cartesian coordinates
void toPolar(double x, double y, double& r, double& a);


//calculates the Cartesian coordinates of a vector using its Polar-form
void toCartesian(double r, double a, double& x, double& y);

//creates a random number inbetween two limtis
int random(int llimit, int ulimit);

