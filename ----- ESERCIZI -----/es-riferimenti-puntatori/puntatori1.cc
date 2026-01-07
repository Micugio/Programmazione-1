#include <iostream>
using namespace std;
 
int main () {

  int x = 5;

  cout << x << endl;
  cout << &x << endl;

  cout << endl;

  int *p = &x;

  cout << "p = " << p << endl;
  cout << "*p = " << *p << endl;
  cout << "&p = " << &p << endl;

  cout << endl;

  int *q = p;

  cout << "q = " << q << endl;
  cout << "*q = " << *q << endl;
  cout << "&q = " << &q << endl;

  
  return 0;
}