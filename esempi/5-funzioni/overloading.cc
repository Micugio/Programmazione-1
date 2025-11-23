//  Example 4.21, page 111
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>

int maxx(int, int);

int maxx(int, int, int);

double maxx(double, double);

double maxx(int, double);


int main()
{
  cout << maxx(99,77) << " " << maxx(55,66,33) << " "
       << maxx(3.4,7.2) << endl;
  cout << maxx(44L,44L) << endl; // errore AMBIGUA
  // cout << maxx(3.1,3) << endl; // errore: AMBIGUA

  return 0;
}

int maxx(int x, int y)
{
  cout << "max int int" << endl;
  return (x > y ? x : y);
}

//  Returns the maxximum of the three given integers:
int maxx(int x, int y, int z)
{
  cout << "max int int int" << endl;
  int m = (x > y ? x : y);
  return (z > m ? z : m);
}

//  Returns the maxximum of the two given real numbers:
double maxx(double x, double y)
{
  cout << "max double double" << endl;
  return (x > y ? x : y);
}

double maxx(int x, double y)
{
  cout << "max int double" << endl;
  return (x > y ? x : y);
}
