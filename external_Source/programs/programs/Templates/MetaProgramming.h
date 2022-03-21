/*********************************************************************
 * MetaProgramming.h
 * Some template classes for meta-programming.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef METAPROGRAMMING_H_
#define METAPROGRAMMING_H_

/*******************************************************
 * z = ipower<x.y>.value
 * z is x to the power of y
 ******************************************************/
template<int x, unsigned y>
struct ipower {
  static const int value = x*ipower<x,y-1>::value;
};
template<int x>
struct ipower<x, 0> {
  static const int value = 1;
};

/*******************************************************
 * List of types: L = empty | node(Type,L)
 ******************************************************/
struct empty {};
template<typename H, typename T> struct node
{
  typedef H head; typedef T tail;
};

/*******************************************************
 * b = same<T,U>.result
 * b is true if and only if T and U are the same type.
 ******************************************************/
template<typename T, typename U> struct same
{
  static const bool result = false;
};
template<typename T> struct same<T, T>
{
  static const bool result = true;
};

/*********************************************************
 * b = member<T,L>.result
 * b is true if and only if type T occurs in type list L.
 *********************************************************/
template<typename T, typename L> struct member
{
  static const bool result =
    same<T,typename L::head>::result ||
    member<T, typename L::tail>::result;
};
template<typename T> struct member<T, empty>
{
  static const bool result = false;
};

#endif /* METAPROGRAMMING_H_ */
