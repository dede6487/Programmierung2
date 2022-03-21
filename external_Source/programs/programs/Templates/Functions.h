/*********************************************************************
 * Functions.h
 * Various template functions.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/**********************************************************
 * c = mmin<T>(a, b);
 * c is the minimum of a and b.
 *
 * Output condition: c in {a,b} and c <= a and c <= b.
 *
 * Note: needs bool operator<(T,T).
 *********************************************************/
template<typename T> T mmin(T a, T b) {
  T c = a;
  if (b < a) c = b;
  return c;
}

/**********************************************************
 * Just for demonstration: min<T> can be overloaded.
 *********************************************************/
template<typename T> T mmin(T a) { return a; }

/**********************************************************
 * fill<N,T>(a, x)
 * fills a with n copies of x.
 *
 * Output condition: a[i] == x for all 0 <= i < N
 *********************************************************/
template<int N, typename T> void fill(T a[N], T x)
{
  for (int i=0; i<N; i++) a[i] = x;
}

/**********************************************************
 * c = conc<N, M, T>(a, b)
 * c is the concatentation of a and b
 *
 * Output condition:
 *   c[i]   == a[i] forall 0 <= i < N
 *   c[i+N] == b[i] forall 0 <= i < M
 *********************************************************/
template<int N, int M, typename T> T* conc(T a[N], T b[M])
{
  T *c = new T[N+M];
  for (int i=0; i<N; i++) c[i] = a[i];
  for (int i=0; i<M; i++) c[i+N] = b[i];
  return c;
}

/*********************************************************
 * z = operator+<T>(x,y)
 * z is the sum of x and y.
 *
 * Note: needs T::getValue().
 ********************************************************/
template<typename T> int operator+(T x, int y)
{
  return x.getValue() + y;
}

/*********************************************************
 * Int
 * A container for an integer value.
 ********************************************************/
class Int {
  int x;
  public:
    Int(int x) { this->x = x; }
    int getValue() { return x; }
};

/********************************************************
 * y = copy<T,U>(x)
 * y is a copy of x
 *
 * Note: needs constructor U(X)
 ******************************************************/
template<typename T, typename U> U copy(T x)
{
  U y = x;
  return y;
}

#endif /* FUNCTIONS_H_ */
