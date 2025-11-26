using namespace std;
#include <iostream>


int main () {
  double y = 3.5;
  double* py = &y;
  double* pypiudue;   // pypiudue punta a y

  cout << y << endl;

  pypiudue = py;   
  *pypiudue = 10.2;

  cout << y << endl; // stampa 10.2
  cout << *py << endl; // stampa 10.2
  cout << *pypiudue << endl; // stampa 10.2 

  return 0;
}

