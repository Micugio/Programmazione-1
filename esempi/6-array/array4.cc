//  Example 5.4, page 130
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>

double c[4];

int main()
{
  double a[4] = {};
  for (int i = 0; i < 4; i++)
    cout << "c[" << i << "] = " << c[i] << endl;
  return 0;
}
