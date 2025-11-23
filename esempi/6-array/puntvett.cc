using namespace std;
#include <iostream>


int main ()
{
  const int dim = 4;
  int v[dim] = {10,20,30,40};
  int *p = v;
  cout << " v = " << (long) v << endl;
  for (int i=0;i<dim;i++)
    cout << " i = " << i <<
            ",&v[i] = " << (long) &p[i] <<
            ",v+i = " << (long) (p+i) <<
            ",v[i] = " << p[i] <<
            ",*(v+i) = " << *(p+i) << endl;
  return 0;
}
