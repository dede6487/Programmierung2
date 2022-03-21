/*
 * Point.cpp
 *
 *  Created on: 03.02.2009
 *      Author: schreine
 */

#include "Point.h"

/*******************************************************************
* Point::zero
* The zero point of the coordinate system
*
* Condition: Point::zero.getX() == Point::zero.getY() ==
*            the default value of T (i.e. typically 0)
******************************************************************/
template<typename T> Point<T> Point<T>::zero;
