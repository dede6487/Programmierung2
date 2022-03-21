/*********************************************************************
 * Tuple.h
 * Generic tuples.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef TUPLE_H_
#define TUPLE_H_

/********************************************************
 * Tuple<T,U>
 * A tuple whose first component is of type T and
 * whose second component is of type U
 *******************************************************/
template<typename T=int, typename U=int> class Tuple
{
  T x; U y;
public:
  Tuple(T a, U b): x(a), y(b) { }
  Tuple() { }
  Tuple(Tuple &t): x(t.x), y(t.y) { }
};

#endif /* TUPLE_H_ */
