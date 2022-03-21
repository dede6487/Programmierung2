/*********************************************************************
 * PhoneBookMain.cpp
 * A phone book application (procedural version).
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include <iostream>

using namespace std;

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

/********************************************************************
 * Entry
 * A phone book entry.
 *******************************************************************/
class Entry {
public:
  const char *name;   // the name of the phone holder
  const char *number; // the corresponding phone number

  /******************************************************************
   * Entry e
   * e is an empty phone book entry
   *
   * Output condition: e is an entry where both name and number
   * are NULL.
   *****************************************************************/
  Entry() { }

  /******************************************************************
   * Entry e(name, number)
   * e is a phone book entry with the denoted name and number.
   *
   * Input condition: name and number must not be NULL and must
   * refer to null-terminated strings.
   *
   * Output condition. e.getName() == name and e.getNumber() == number
   *
   * Effect: the entry stores duplicates of name and number i.e.
   * any subsequent changes to name/number will not affect the entry.
   *****************************************************************/
  Entry(char* na, char *nu): name(copy(na)), number(copy(nu)) { }

  /******************************************************************
   * delete e
   * Free resources held by e.
   *
   * Effect: deletes the copies of name and number held by e.
   *****************************************************************/
  ~Entry() { delete[] name; delete[] number; }

  /******************************************************************
   * name = e.getName()
   * name is the name held by e
   *
   * Output condition: name is the name of the phone book holder of e
   *****************************************************************/
  const char* getName() const { return name; }

  /******************************************************************
   * number = e.getNumber()
   * number is the number held by e
   *
   * Output condition: number is the phone book number in e.
   *****************************************************************/
  const char* getNumber() const { return number; }
};

/********************************************************************
 * e = readEntry()
 * Read phone book entry and returns it as e.
 *
 * Effect: asks for the data of a phone book entry. If no more
 * data are provided, NULL is returned. Otherwise, a pointer
 * to a newly allocated and correspondingly initialized entry
 * is returned.
 *******************************************************************/
Entry* readEntry()
{
  cout << "Another entry (y/n)? "; char ch[2]; cin.getline(ch, 2);
  if (ch[0] != 'y') return NULL;
  cout << "Name: "; char name[100]; cin.getline(name, 100);
  cout << "Number: "; char number[100]; cin.getline(number, 100);
  return new Entry(name, number);
}

/********************************************************************
 * n = readPhoneBook(book, N)
 * Reads at most N phone book entries and sets n to the number read.
 *
 * Input condition: book is not NULL and refers to an array of at
 * least N entries.
 *
 * Effect: repeatedly (at most N times) asks user for a phone book
 * entry and fills the book accordingly until the book is full or
 * no more entries are provided. n is the number of phone book
 * entries with which the book was actually filled.
 ********************************************************************/
int readPhoneBook(Entry **book, int N)
{
  for (int i=0; i<N; i++)
  {
    Entry *entry = readEntry();
    if (entry == NULL) return i;
    book[i] = entry;
  }
  return N;
}

/********************************************************************
 * number = getNumber(book n, name)
 * Get number associated to name in book.
 *
 * Input condition: book is not NULL and refers to a phone book
 * with n entries. name is not NULL and refers to a null-terminated
 * string.
 *
 * Output condition: if an entry with phone book holder "name"
 * is in the book, number is the associated phone number,
 * otherwise number is NULL.
 *******************************************************************/
const char* getNumber(Entry **book, int n, char *name) {
  for (int i=0; i<n; i++) {
    Entry *entry = book[i];
    if (strcmp(name, entry->getName()) == 0)
      return entry->getNumber();
  }
  return NULL;
}

/*******************************************************************
 * usePhoneBook(book, n)
 * Use phone book of n entries.
 *
 * Input condition: book is not NULL and refers to a phone book
 * with n entries.
 *
 * Effect: repeatedly asks the user whether another phone book
 * lookup is requested. If yes, a name is read, the phone
 * book is looked up, and the result of the lookup is printed.
 * Terminates when the user does not want another lookup.
 ****************************************************************/
void usePhoneBook(Entry** book, int n) {
  while (true) {
    cout << "Another lookup (y/n)? ";
    char ch[2]; cin.getline(ch,2); if (ch[0] != 'y') return;
    cout << "Name: "; char name[100]; cin.getline(name, 100);
    const char *number = getNumber(book, n, name);
    if (number == NULL) { cout << "Name not found\n"; continue; }
    cout << "Number: " << number << "\n";
  }
}

/****************************************************************
 * deletePhoneBook(book, n)
 * delete phone book with n entries.
 *
 * Input condition: book is not NULL and refers to a phone book
 * with n entries.
 *
 * Effect: frees all resources held by book.
 ***************************************************************/
void deletePhoneBook(Entry **book, int n)
{
  for (int i=0; i<n; i++)
    delete book[i];
}

// the maximum size of the phone book (numer of entries)
const int N = 100;

/****************************************************************
 * mainPhoneBook()
 * fills a phone book and uses it.
 *
 * Effect: in the first step, a phone book with at most N entries
 * is created and filled by information (name of phone book
 * holder, associated phone number) provided by the user.
 *
 * In the second step, the phone book is used by repeatedly
 * asking for a name which is looked up in the phone book
 * such that the corresponding phone number is printed.
 ****************************************************************/
void mainPhoneBook()
{
  Entry* book[N];
  int n = readPhoneBook(book, N);
  usePhoneBook(book, n);
  deletePhoneBook(book, n);
}

/****************************************************************
 * main()
 * a simple phone book application
 *
 * For the specification of the application, see mainPhoneBook().
 ***************************************************************/
int main()
{
  mainPhoneBook();
}

