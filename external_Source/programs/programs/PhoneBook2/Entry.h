/*********************************************************************
 * Entry.h
 * A phone book entry.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/
#ifndef ENTRY_H_
#define ENTRY_H_

#include <cstring>

/**************************************************************************
 * A phone book entry holding a name and an associated phone number.
 *************************************************************************/
class Entry {
public:
  const char *name;   // the name of the phone book holder
  const char *number; // the associated phone number

  /***********************************************************************
   * Entry e
   * e is an empty phone book entry
   *
   * Output condition: both name and number are NULL.
   *********************************************************************/
  Entry() { }

  /***********************************************************************
   * Entry e(name, number)
   * e is a phone book entry with denoted name and number
   *
   * Input condition: name and number are not NULL and refer to
   * null-terminated strings.
   *
   * Output condition: e holds copies of name and number (subsequent
   * changes to name and number will thus not affect the entry).
   *********************************************************************/
  Entry(char* na, char *nu): name(copy(na)), number(copy(nu)) { }

  /**********************************************************************
   * delete e
   * delete resources held by phone book entry e.
   *
   * Effect: deletes the copies of name and number held by e.
   *********************************************************************/
  ~Entry() { delete[] name; delete[] number; }

  /***********************************************************************
   * name = e.getName()
   * name is the name of the phone holder associated to e.
   *
   * Output condition: returns the name of the phone holder.
   **********************************************************************/
  const char* getName() const { return name; }

  /***********************************************************************
   * number = e.getNumber()
   * number is the number of the phone associated to e.
   *
   * Output condition: returns the phone number.
   **********************************************************************/
  const char* getNumber() const { return number; }
  bool hasName(char *name) const { return strcmp(name, this->name) == 0; }

  /*********************************************************************
   * t = copy(s)
   * t is an immutable copy of s
   *
   * Input condition: s != NULL and s refers to a null-terminated string
   *
   * Output condition: s is a duplicate of t i.e. a string of same
   * length and with the same content.
   ********************************************************************/
  static const char* copy(char *str) {
    int n = strlen(str);
    char* result = new char[n+1];
    strncpy(result, str, n+1);
    return result;
  }
};

#endif /* ENTRY_H_ */
