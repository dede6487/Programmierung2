/*********************************************************************
 * Words.cpp
 * Reads text and prints each word on a separate line.
 *
 * Author: Wolfgang Schreiner <Wolfgang.Schreiner@risc.uni-linz.ac.at>
 * Date of last modification: 5.2.2009
 *
 * (c) Wolfgang Schreiner, 2009
 ********************************************************************/

#include <string>
#include <iostream>

using namespace std;

// prints every word of text on a new line
void printWords(const string& text);

/*********************************************************************
 * main()
 * Reads and prints text.
 *
 * Reads all available text from the standard input and prints
 * out each word of the text on a new line of the standard output;
 * the characters separating the words are not printed.
 *
 * A word is a sequence of lower- and/or upper-case ASCII letters.
 ********************************************************************/
int main()
{
  while (true)
  {
    string line;
    bool okay = getline(cin, line);
    if (!okay) break;
    printWords(line);
  }
}

// all characters allowed in a word
const char LETTERS[] =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/*********************************************************************
 * printWords(text)
 * Prints every word of text on a new line.
 *
 * Prints every word of text on a new line in the order in which
 * they occur in the text.
 ********************************************************************/
void printWords(const string& text)
{
  int i = 0;               // current position in text
  int end = text.length(); // the first position not in text

  // find next word at position at or after i
  while (i < end)
  {
    // find beginning of a word
    int a = text.find_first_of(LETTERS, i);
    if (a == -1) break;

    // find end of the word (can be end of text)
    int b = text.find_first_not_of(LETTERS, a);
    if (b == -1) b = end;

    // print out word
    cout << text.substr(a, b-a) << "\n";

    // start position for next search
    i = b+1;
  }
}

