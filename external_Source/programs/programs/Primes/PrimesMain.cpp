/*********************************************************************
 * PrimesMain.cpp
 * A prime number computation.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#include <iostream>

using namespace std;

/********************************************************************
 * PrimeTable
 * A resizable table of prime numbers.
 *******************************************************************/
class PrimeTable
{
public:
  int N;  // the size of the table
  int n;  // the number of elements actually contained in it
  int *p; // the table itself

  PrimeTable();        // create the table
  ~PrimeTable();       // delete the table

  bool isPrime(int c); // check whether candidate c is prime
  void add(int c);     // add a new prime c to the table

  void resize();       // make table bigger
};


/***********************************************************************
 * printPrimes(n)
 * prints all prime numbers less than n.
 **********************************************************************/
void printPrimes(int n)
{
  if (n < 2) return;
  cout << 2 << "\n";
  PrimeTable p; // table to hold all odd primes computed so far
  for (int c = 3; c < n; c += 2)
  {
    if (!p.isPrime(c)) continue;
    cout << c << "\n";
    p.add(c);
  }
}

/**********************************************************************
 * main()
 * Prints all prime numbers less than 1000.
 *********************************************************************/
int main()
{
  printPrimes(1000);

}

/*******************************************************************
 * Primetable p
 * p is an empty prime table.
 *
 * Output condition: p is a table that does not hold any number yet.
 *******************************************************************/
PrimeTable::PrimeTable(): N(100), n(0), p(new int[N]) { }

/*******************************************************************
 * delete p
 * Delete prime table p
 *
 * Effect: deletes all resources held by p.
 ******************************************************************/
PrimeTable::~PrimeTable() { delete[] p; }

/*******************************************************************
 * b = p.isPrime(c)
 * b indicates whether c is prime with respect to all primes in p.
 *
 * Output condition: b is true if and only if c cannot be
 * divided exactly by any number in p.
 ******************************************************************/
bool PrimeTable::isPrime(int c) {
  for (int i=0; i<n; i++)
    if (c % p[i] == 0) return false;
  return true;
}

/*******************************************************************
 * p.add(c)
 * c is added to p.
 *
 * Output condition: p holds c.
 ******************************************************************/
void PrimeTable::add(int c) {
  if (n == N) resize();
  p[n] = c;
  n = n+1;
}

/*******************************************************************
 * p.resize()
 * Ensures that p is not full.
 *
 * Effect: allocates a bigger table and transfers all numbers to
 * the new table; the old table is deleted.
 ******************************************************************/
void PrimeTable::resize() {
  int N0 = 2*N+1;
  int *p0 = new int[N0];
  for (int i=0; i<n; i++) p0[i] = p[i];
  delete[] p;
  N = N0; p = p0;
}
