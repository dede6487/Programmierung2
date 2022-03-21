/*********************************************************************
 * PhoneBook.h
 * A phone book.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include "PhoneBook.h"

/********************************************************************
 * PhoneBook book
 * Allocates a new phone book.
 *
 * Output condition: the new phone book has no entries.
 ******************************************************************/
PhoneBook::PhoneBook(): N(100), n(0), b(new Entry*[N]) {}

/********************************************************************
 * delete book
 * Deletes resources held by phone book.
 *
 * Effect: the phone book entries and the phone book array are discarded.
 ********************************************************************/
PhoneBook::~PhoneBook() {
  for (int i=0; i<n; i++) delete b[i]; // delete entry
  delete[] b;                          // delete book itself
}

/**********************************************************************
 * book.add(name, number)
 * Add new entry with denoted name and number to phone book.
 *
 * Input condition: name and number are not NULL and refer to
 * null-terminated strings.
 *
 * Effect: a new phone book entry with copies of name and number
 * is created and stored in the phone book (subsequent changes
 * to name and number do not affect the phone book entry).
 *********************************************************************/
void PhoneBook::add(char *name, char *number) {
  if (n == N) resize();
  b[n] = new Entry(name, number);
  n = n+1;
}

/**********************************************************************
 * number = book.search(name)
 * number is the phone number associated to the phone holder with
 * the denoted name in the phone book.
 *
 * Input condition: name is not NULL and refers to a null-terminated
 * string.
 *
 * Output condition: if name appears in the phone book, number is
 * the associated phone number, otherwise number is NULL.
 **********************************************************************/
const char* PhoneBook::search(char *name) {
  for (int i=0; i<n; i++) {
    Entry *entry = b[i];
    if (entry->hasName(name)) return entry->getNumber();
  }
  return NULL;
}

/**********************************************************************
 * book.resize()
 * Ensure that the phone book is not full.
 *
 * Effect: a new bigger copy of the phone book array is created
 * and the entries are transferred to the copy. The original array
 * is deleted.
 *********************************************************************/
void PhoneBook::resize() {
  int N0 = 2*N+1; Entry **b0 = new Entry*[N0];
  for (int i=0; i<n; i++) b0[i] = b[i]; // only *pointers* are copied
  delete[] b; N = N0; b = b0;
}
