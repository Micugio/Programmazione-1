//  Example 7.7, page 192
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>
#include <cctype>

int main()
{
  char ch, pre = ' ';  // NOTA: pre = ' ', così diventa maiuscola anche la prima lettera della prima parola.
  while (cin.get(ch)) {
    if (pre == ' ' || pre == '\n')  // (Se carattere precedente è uno spazio o un a capo)
       cout.put(char(toupper(ch)));
    else 
       cout.put(ch);
    pre = ch;
  }
  return 0;
}
