/*********************************************************************
 * Tuple.h
 * Generic arrays.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

/*********************************************************************
 * Array<N,T>
 * Arrays of size N with elements of type T.
 ********************************************************************/
template<int N=100, typename T=int> class Array
{
protected:
  T a[N];
public:
  Array(T x = 0) { for (int i=0; i<N; i++) a[i] = x; }
  virtual ~Array() { }
  int length() { return N; }
  T& operator[](int i)
  {
    if (i < 0 || i >= N) exit(-1);
    return a[i];
  }
  typedef T value_type;
};

/*********************************************************************
 * Array<T>
 * Arrays of size 1 with elements of type T.
 ********************************************************************/
template<typename T> class Array<1, T>
{
protected:
  T a;
public:
  Array(T x = 0) { std::cout << "init\n"; a = x; }
  virtual ~Array() { } // support subclasses with virtual functions
  int length() { return 1; }
  T& operator[](int i)
  {
    std::cout << "one\n";
    if (i != 0) exit(-1);
    return a;
  }
  typedef T value_type;
};

/********************************************************************
 * SortableArray<N,T>
 * Arrays of size N and element type T with an ordering function
 * isSorted(T,T) attached to the type.
 *******************************************************************/
template<int N, typename T> class SortableArray : public Array<N, T>
{
public:
  static bool isSorted(T a, T b)
  { return a <= b ; }
};

/********************************************************************
 * SortableArray<N,char*>
 * String arrays of size N to be sorted in lexicograpical order.
 *******************************************************************/
template<int N> class SortableArray<N, char *>: public Array<N, char*>
{
public:
  static bool isSorted(char *a, char *b)
  { return strcmp(a, b) <= 0; }
};

/********************************************************************
 * SortableArray2<N,T>
 * Arrays of size N and element type T with an ordering function
 * isSorted(int,int) (on indices) attached to every object.
 *******************************************************************/
template<int N, typename T> class SortableArray2: public Array<N, T>
{
public:
  virtual bool isSorted(int i, int j)
  { return this->a[i] <= this->a[j]; }
};

/********************************************************************
 * SortableArray2<N,char*>
 * String arrays of size N with an ordering function
 * isSorted(int,int) (on indices) attached to every object.
 *******************************************************************/
template<int N> class SortableArray2<N, char *>: public Array<N, char*>
{
public:
  virtual bool isSorted(int i, int j)
  { return strcmp(this->a[i],this->a[j])<=0; }
};

/********************************************************************
 * ReverseSortableArray<N,T>
 * Arrays of size N and element type T with ordering *reverted*
 * compared to SortableArray2<N,T>
 *******************************************************************/
template<int N, typename T> class ReverseSortedArray: public SortableArray2<N, T>
{
public:
  virtual bool isSorted(int i, int j)
  { return !SortableArray2<N, T>::isSorted(i, j); }
};

#endif /* ARRAY_H_ */
