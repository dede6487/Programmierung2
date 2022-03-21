/*********************************************************************
 * Point.h
 * A generic point.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef POINT_H_
#define POINT_H_

/*********************************************************************
 * Point<T>
 * A point in the two dimensional plain where both coordinates
 * are of type T (which must support arithmetic).
 ********************************************************************/
template<typename T> class Point
{
  T x; // the horizontal coordinate
  T y; // the vertical coordinate
public:
  /*******************************************************************
   * Point p(a, b)
   * A point with x-coordinate a and y-coordinate b.
   *
   * Output condition. p.getX() == a and p.getY() == b.
   *****************************************************************/
  Point(T a, T b): x(a), y(b) { }

  /******************************************************************
   * x = p.getX()
   * x is the x-coordinate of p.
   *
   * Output condition: x is the horizontal coordinate.
   *****************************************************************/
  T getX() { return x; }

  /******************************************************************
   * y = p.getY()
   * y is the y-coordinate of p.
   *
   * Output condition: y is the vertical coordinate.
   *****************************************************************/
  T getY() { return y; }

  /******************************************************************
   * q = p.flip()
   * q is p flipped at the center point of the coordinate system.
   *
   * Output condition: q.getX() == -p.getX() and q.getY() == -p.getY()
   *****************************************************************/
  Point flip() { return Point(-x,-y); }

  /*******************************************************************
   * Point::zero
   * The zero point of the coordinate system
   *
   * Condition: Point::zero.getX() == Point::zero.getY() ==
   *            the default value of T (i.e. typically 0)
   ******************************************************************/
  static Point zero;

  /******************************************************************
   * m = midpoint(p, q)
   * m is the point in the middle between p and q
   *
   * Output condition: 2*(m.getX()) == p.getX()+q.getX() and
   *                   2*(m.getY()) == p.getY()+q.getY()
   *****************************************************************/
  static Point midpoint(Point p, Point q)
  { return Point((p.x+q.x)/2, (p.y+q.y)/2); }

  /******************************************************************
   * q = copy(p)
   * q is a copy of p (not p itself)
   *
   * Output condition: q.getX() == p.getX() and q.getY() == p.getY()
   *****************************************************************/
  static Point copy(Point p) { return Point(p.x, p.y); }
};

// the implementation
#include "Point.cpp"

#endif /* POINT_H_ */
