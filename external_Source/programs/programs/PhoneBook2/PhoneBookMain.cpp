/*********************************************************************
 * PhoneBookMain.cpp
 * A phone book application (object-oriented version).
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include <iostream>
#include "PhoneBook.h"

using namespace std;

/********************************************************************
 * readPhoneBook(book)
 * Reads phone book entries and fills the phone book with it.
 *
 * Effect: repeatedly asks user for a phone book entry and fills
 * the book accordingly until no more entries are provided.
 ********************************************************************/
void readPhoneBook(PhoneBook &book) {
  while (true)
  {
    cout << "Another entry (y/n)? ";
    char ch[2]; cin.getline(ch, 2); if (ch[0] != 'y') return;
    cout << "Name: "; char name[100]; cin.getline(name, 100);
    cout << "Number: "; char number[100]; cin.getline(number, 100);
    book.add(name, number); // an entry is added to the book
  }
}

/*******************************************************************
 * usePhoneBook(book)
 * Use phone book.
 *
 * Effect: repeatedly asks the user whether another phone book
 * lookup is requested. If yes, a name is read, the phone
 * book is looked up, and the result of the lookup is printed.
 * Terminates when the user does not want another lookup.
 ****************************************************************/
void usePhoneBook(PhoneBook &book)
{
  while (true)
  {
    cout << "Another lookup (y/n)? ";
    char ch[2]; cin.getline(ch, 2); if (ch[0] != 'y') return;
    cout << "Name: "; char name[100]; cin.getline(name, 100);
    const char *number = book.search(name); // name looked up in book
    if (number == NULL) { cout << "Name not found\n"; continue; }
    cout << "Number: " << number << "\n";
  }
}

/****************************************************************
 * mainPhoneBook()
 * fills a phone book and uses it.
 *
 * Effect: in the first step, a phone book
 * is created and filled by information (name of phone book
 * holder, associated phone number) provided by the user.
 *
 * In the second step, the phone book is used by repeatedly
 * asking for a name which is looked up in the phone book
 * such that the corresponding phone number is printed.
 ****************************************************************/
void mainPhoneBook()
{
  PhoneBook book;      // empty book is created by default constructor
  readPhoneBook(book); // book is filled
  usePhoneBook(book);  // book is used
}                      // book is destroyed by destructor

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
