using namespace std;
#include <iostream>

int main() {
  int n = 1;
  int *p = &n;
  int &r = *p;
  cout << "r = " << r << endl;
  cout << "p = " << *p << endl;

  int m = 2;
  p = &m;
  cout << "r = " << r << endl;
  cout << "p = " << *p << endl;

  // Quanto vale r?
  // r "segue" p?
  return 0;
}
