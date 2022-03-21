/*********************************************************************
 * Point2.h
 * A generic point.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef POINT2_H_
#define POINT2_H_

/*********************************************************************
 * Point2<T>
 * A point in the two dimensional plain where both coordinates
 * are of type T (which must support arithmetic).
 ********************************************************************/
template<typename T> class Point2
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
  Point2(T a, T b);

  /******************************************************************
   * x = p.getX()
   * x is the x-coordinate of p.
   *
   * Output condition: x is the horizontal coordinate.
   *****************************************************************/
  T getX();

  /******************************************************************
   * y = p.getY()
   * y is the y-coordinate of p.
   *
   * Output condition: y is the vertical coordinate.
   *****************************************************************/
   T getY();

   /******************************************************************
    * q = p.flip()
    * q is p flipped at the center point of the coordinate system.
    *
    * Output condition: q.getX() == -p.getX() and q.getY() == -p.getY()
    *****************************************************************/
   Point2 flip();

   /*******************************************************************
    * Point::zero
    * The zero point of the coordinate system
    *
    * Condition: Point::zero.getX() == Point::zero.getY() ==
    *            the default value of T (i.e. typically 0)
    ******************************************************************/
   static Point2 zero;

   /******************************************************************
    * m = midpoint(p, q)
    * m is the point in the middle between p and q
    *
    * Output condition: 2*(m.getX()) == p.getX()+q.getX() and
    *                   2*(m.getY()) == p.getY()+q.getY()
    *****************************************************************/
   static Point2 midpoint(Point2 p, Point2 q);

   /******************************************************************
    * q = copy(p)
    * q is a copy of p (not p itself)
    *
    * Output condition: q.getX() == p.getX() and q.getY() == p.getY()
    *****************************************************************/
   static Point2 copy(Point2 p);
};

// implementation
#include "Point2.cpp"

#endif /* POINT2_H_ */
