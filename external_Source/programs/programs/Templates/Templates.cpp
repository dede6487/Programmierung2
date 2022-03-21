/*
 * Templates.cpp
 *
 *  Created on: 25.01.2009
 *      Author: schreine
 */
#include <iostream>

using namespace std;

#include "Functions.h"
#include "Point.h"
#include "Point2.h"
#include "Tuple.h"
#include "Container.h"
#include "Variable.h"
#include "Array.h"
#include "Sorting.h"
#include "MetaProgramming.h"

// a comparison function on integers and strings
inline bool sortedInt(int x, int y) { return x <= y; }
inline bool sortedString(char* x, char* y)
{ return strcmp(x, y) < 0; }

/************************************************************
 * set(a, start, end, x)
 * set all values in a[start..end-1] to x
 * (demonstrates use of template as template parameter)
 ***********************************************************/
template<template<int, typename> class C, int N, typename T>
void set(C<N,T>& a, int start, int end, T x) {
  for (int i=start; i<end; i++) a[i] = x;
}

/************************************************************
 * x = geta<C>(a, i)
 * x is element of a at position i
 * (demonstrates use of typename)
 ***********************************************************/
template<typename C>
typename C::value_type geta(C a, int i) {
  return a[i];
}

int main()
{
  /***********************************************************
   * Use of some template functions
   **********************************************************/

  int x = mmin<int>(10, 20);         // explicit instantiation of min<int>
  float y = mmin<float>(10.4, 20.3); // explicit instantiation of min<float>
  int z = mmin(10, 20);              // automatic instantiation of min<int>
  std::cout << x << y << z << "\n";
  int w = mmin(2);
  std::cout << w << "\n";

  int a[3];
  fill<3,int>(a, 7);
  fill<3>(a,7);

  int b[5];
  int *c = conc<3,4>(a,b);
  std::cout << c[0];

  int e = copy<int,int>(5);
  std::cout << e;

  /***********************************************************
   * Use of some template classes
   **********************************************************/

  Point<int> p(5, 3);
  p.flip();
  cout << p.getX();
  Point<double> q(3.14, 2.71);
  Point<double> s = Point<double>::midpoint(q, q);
  Point<double> r = Point<double>::copy(q);
  Point<int> p2 = p.flip();
  Point2<int> pa(3, 5);

  Tuple<double, double> tu(3.14, 2.71);
  Tuple<double> tv(3.14, 2);
  Tuple<> tw(3, 2);
  Tuple<int, int> t0(3, 0);
  Container<Tuple<int,int> > u0(t0);
  Container<int> v0(5);

  Variable<int> var(0);
  var.set(1);    // non-template function set
  var.set(2.5);  // template function set<double>

  /***********************************************************
   * Sorting
   **********************************************************/

  cout << "\nSorting V1:\n";
  int as[3] = {3, 1, 2};
  sortV1(as, 3);
  cout << as[0] << " " << as[1] << " " << as[2] << "\n";
  char* bs[3] = {"c", "a", "b"};
  sortV1(bs, 3);
  cout << bs[0] << " " << bs[1] << " " << bs[2] << "\n";

  cout << "\nSorting V2:\n";
  int cs[3] = {3, 1, 2};
  sortV2<int,IntComparator>(cs, 3);
  cout << cs[0] << " " << cs[1] << " " << cs[2] << "\n";
  char* ds[3] = {"c", "a", "b"};
  sortV2<char*,StringComparator>(ds, 3);
  cout << ds[0] << " " << ds[1] << " " << ds[2] << "\n";

  cout << "\nSorting V3:\n";
  int es[3] = {3, 1, 2};
  sortV3<3>(es);
  cout << es[0] << " " << es[1] << " " << es[2] << "\n";
  char* fs[3] = {"c", "a", "b"};
  sortV3<3>(fs);
  cout << fs[0] << " " << fs[1] << " " << fs[2] << "\n";

  cout << "\nSorting V4:\n";
  int gs[3] = {3, 1, 2};
  sortV4<int,sortedInt>(gs, 3);
  cout << gs[0] << " " << gs[1] << " " << gs[2] << "\n";
  char* hs[3] = {"c", "a", "b"};
  sortV4<char*,sortedString>(hs, 3);
  cout << hs[0] << " " << hs[1] << " " << hs[2] << "\n";

  cout << "\nSorting V6:\n";
  Array<2,int> a0; a0[0]=2; a0[1]=1;
  sortV6<2,int>(a0);
  cout << a0[0] << " " << a0[1] << "\n";
  Array<2,char*> b0; b0[0]="b"; b0[1]="a";
  sortV6<2,char*>(b0);
  cout << b0[0] << " " << b0[1] << "\n";

  cout << "\nSorting V7:\n";
  SortableArray<2,int> c0; c0[0]=2; c0[1]=1;
  sortV7<2,int>(c0);
  cout << c0[0] << " " << c0[1] << "\n";
  SortableArray<2,char*> d0; d0[0]="b"; d0[1]="a";
  sortV7<2,char*>(d0);
  cout << d0[0] << " " << d0[1] << "\n";

  cout << "\nSorting V8:\n";
  SortableArray2<2,int> e0; e0[0]=2; e0[1]=1;
  sortV8<2,int>(e0);
  cout << e0[0] << " " << e0[1] << "\n";
  SortableArray2<2,char*> f0; f0[0]="b"; f0[1]="a";
  sortV8<2,char*>(f0);
  cout << f0[0] << " " << f0[1] << "\n";

  cout << "\nSorting V8 (reverted):\n";
  ReverseSortedArray<2,int> g0; g0[0]=1; g0[1]=2;
  sortV8<2,int>(g0);
  cout << g0[0] << " " << g0[1] << "\n";
  ReverseSortedArray<2,char*> h0; h0[0]="a"; h0[1]="b";
  sortV8<2,char*>(h0);
  cout << h0[0] << " " << h0[1] << "\n";

  cout << "\n";

  /***********************************************************
   * Advanced use of templates
   **********************************************************/
  Array<100,int> arr0;
  set(arr0, 0, 50, 1);   // automatic: set<Array,100,int>
  set(arr0, 50, 100, 2); // automatic: set<Array,100,int>
  cout << geta(arr0, 50) << "\n";

  Array<100,double> arr1;
  set(arr1, 0, 100, 1.5); // automatic: set<Array,100,double>
  cout << geta(arr1, 50) << "\n";

  /***********************************************************
   * Metaprogramming
   **********************************************************/

  // computation of 2^5 at compile-time
  std::cout << ipower<2,5>::value << "\n";

  // processing a list of types
  typedef node<int, node<bool, node<char, empty> > > typelist;
  std::cout << member<char, typelist>::result << "\n";
}

