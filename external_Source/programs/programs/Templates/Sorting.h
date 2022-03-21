/*********************************************************************
 * Sorting.h
 * Various generic sorting functions.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef SORTING_H_
#define SORTING_H_

#include "Array.h"

/*********************************************************************
 * sortV1<T>(a, n)
 * sorts array a of length n
 *
 * Note: needs bool operator<(T, T)
 *******************************************************************/
template<typename T> void sortV1(T a[], int n)
{
  for (int i=0; i<n-1; i++)
  {
    for (int j=n-1; i<j; j--)
    {
      if (a[j] < a[j-1])
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}


/*********************************************************************
 * sortV1<char*>(a, n)
 * sorts string array a of length n
 *******************************************************************/
template<> void sortV1<char*>(char* a[], int n)
{
  for (int i=0; i<n-1; i++)
  {
    for (int j=n-1; i<j; j--)
    {
      if (strcmp(a[j],a[j-1]) < 0)
      {
        char* b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

/*********************************************************************
 * sortV2<T,C>(a, n)
 * sorts array a of length n
 *
 * Note: needs bool C::operator<(T, T)
 *******************************************************************/
template<typename T, typename C> void sortV2(T a[], int n) {
  for (int i=0; i<n-1; i++) {
    for (int j=n-1; i<j; j--) {
      if (!C::isSorted(a[j-1],a[j])) {
        T b = a[j]; a[j] = a[j-1]; a[j-1] = b;
      }
    }
  }
}

// an integer comperator suitable as C for above function
class IntComparator { public:
  static bool isSorted(int a, int b) { return a <= b ; }
};

// a string comparator suitable as C for above function
class StringComparator { public:
  static bool isSorted(char *a, char *b) { return strcmp(a, b) <= 0; }
};

/*********************************************************************
 * sortV3<N,T>(a)
 * sorts array a of length N
 *
 * Note: needs bool operator<(T, T)
 ********************************************************************/
template<int N, typename T> void sortV3(T a[N])
{
  for (int i=0; i<N-1; i++)
  {
    for (int j=N-1; i<j; j--)
    {
      if (a[j] < a[j-1])
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

/*********************************************************************
 * sortV4<T,isSorted>(a, n)
 * sorts array a of length n with respect to order "isSorted".
 ********************************************************************/
template<typename T, bool isSorted(T,T)> void sortV4(T a[], int n)
{
  for (int i=0; i<n-1; i++)
  {
    for (int j=n-1; i<j; j--)
    {
      if (!isSorted(a[j-1], a[j]))
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

// generic ordering class needed for sortV6
template<typename T> class Comparator { public:
  static bool isSorted(T a, T b) { return a <= b ; }
};

// a special string ordering class suitable for sortV6
template<> class Comparator<char*> { public:
  static bool isSorted(char *a, char *b) { return strcmp(a, b) <= 0; }
};

/*********************************************************************
 * sortV6<N,T>(a)
 * sorts array a of length N
 *
 * Note: needs bool Comperator<T>::operator<(T, T)
 ********************************************************************/
template<int N, typename T> void sortV6(Array<N,T> &a)
{
  for (int i=0; i<N-1; i++)
  {
    for (int j=N-1; i<j; j--)
    {
      if (!Comparator<T>::isSorted(a[j-1],a[j]))
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

/*********************************************************************
 * sortV7<N,T>(a)
 * sorts array a of length N with sorting function attached
 * to array type.
 ********************************************************************/
template<int N, typename T> void sortV7(SortableArray<N,T> &a)
{
  for (int i=0; i<N-1; i++)
  {
    for (int j=N-1; i<j; j--)
    {
      if (!SortableArray<N,T>::isSorted(a[j-1],a[j]))
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

/*********************************************************************
 * sortV8<N,T>(a)
 * sorts array a of length N with sorting function attached to
 * array object.
 ********************************************************************/
template<int N, typename T> void sortV8(SortableArray2<N, T> &a)
{
  for (int i=0; i<N-1; i++)
  {
    for (int j=N-1; i<j; j--)
    {
      if (!a.isSorted(j-1,j))
      {
        T b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
      }
    }
  }
}

#endif /* SORTING_H_ */
