/*
 * Point2.cpp
 *
 *  Created on: 03.02.2009
 *      Author: schreine
 */

#include "Point2.h"

/*******************************************************************
 * Point p(a, b)
 * A point with x-coordinate a and y-coordinate b.
 *
 * Output condition. p.getX() == a and p.getY() == b.
 *****************************************************************/
template<typename T> Point2<T>::Point2(T a, T b): x(a), y(b) { }

/******************************************************************
 * x = p.getX()
 * x is the x-coordinate of p.
 *
 * Output condition: x is the horizontal coordinate.
 *****************************************************************/
template<typename T> T Point2<T>::getX() { return x; }

/******************************************************************
 * y = p.getY()
 * y is the y-coordinate of p.
 *
 * Output condition: y is the vertical coordinate.
 *****************************************************************/
template<typename T> T Point2<T>::getY() { return y; }

/******************************************************************
 * q = p.flip()
 * q is p flipped at the center point of the coordinate system.
 *
 * Output condition: q.getX() == -p.getX() and q.getY() == -p.getY()
 *****************************************************************/
template<typename T> Point2<T> Point2<T>::flip() { return Point2(-x,-y); }

/*******************************************************************
 * Point::zero
 * The zero point of the coordinate system
 *
 * Condition: Point::zero.getX() == Point::zero.getY() ==
 *            the default value of T (i.e. typically 0)
 ******************************************************************/
template<typename T> Point2<T> Point2<T>::zero;

/******************************************************************
 * m = midpoint(p, q)
 * m is the point in the middle between p and q
 *
 * Output condition: 2*(m.getX()) == p.getX()+q.getX() and
 *                   2*(m.getY()) == p.getY()+q.getY()
 *****************************************************************/
template<typename T> Point2<T> Point2<T>::midpoint(Point2 p, Point2 q)
{ return Point2((p.x+q.x)/2, (p.y+q.y)/2); }

/******************************************************************
 * q = copy(p)
 * q is a copy of p (not p itself)
 *
 * Output condition: q.getX() == p.getX() and q.getY() == p.getY()
 *****************************************************************/
template<typename T> Point2<T> Point2<T>::copy(Point2 p)
{ return Point2(p.x, p.y); }
