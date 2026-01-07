#include <iostream>
using namespace std;

#include "fact4.h"
// long long fact(int);

int main()
{
  int  num;
  long long fattoriale;

  cout << "Dammi il numero: ";
  cin >> num;
  fattoriale=fact(num);
  cout  << "Fact = "  << fattoriale   << endl;
  return 0;
}
