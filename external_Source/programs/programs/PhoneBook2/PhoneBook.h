/*********************************************************************
 * PhoneBook.h
 * A phone book.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Entry.h"

/********************************************************************
 * A phone book represented by a dynamically resized array
 * of phone book entries.
 *******************************************************************/
class PhoneBook {
public:
  int N;        // the size of the book
  int n;        // the number of entries allocated in it
  Entry **b;    // the book itself, a table of entry *pointers*

  PhoneBook();   // construct the book
  ~PhoneBook();  // delete the book

  void add(char *name, char *number); // add an entry
  const char* search(char *name);     // search for a number
  void resize();                      // make the book bigger
};

#endif /* PHONEBOOK_H_ */
