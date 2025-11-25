using namespace std;
#include <iostream>


int main () {
  int x;
  int * px = &x;
  long double y;
  long double * py = &y, *pypiudue;
  
  cout << "Size(int) = " << sizeof(int) << endl;
  cout << "Address(x) = " << (long) &x << endl;
  cout << "px = " << (long) px << endl;
  cout << endl;  

  px += 2; // (cioè +8 perchè un sizeof(int)=4 )
  cout << "px = " << (long) px << endl;  
  px -= 3;
  cout << "px = " << (long) px << endl;  
  px++;
  cout << "px = " << (long) px << endl; 
  cout << endl;   
   
  cout << "Size(long double) = " << sizeof(long double) << endl;
  cout << "Address(y) = " << (long) &y << endl;
  cout << "py = " << (long) py << endl;
  cout << endl;

  py += 2;
  cout << "py = " << (long) py << endl; 
  pypiudue = py;
  cout << endl;
 
  py -= 3;
  cout << "py = " << (long) py << endl;  
  py +=1;
  cout << "py = " << (long) py << endl;  
  cout << endl;

  cout << "pypiudue = " << (long) pypiudue << endl; 
  cout << "py =       " << (long) py << endl;  
  cout << "pypiudue-py = " << pypiudue-py << endl;
  cout << "py-pypiudue = " << py-pypiudue << endl;
  cout << endl;

  cout << "(pypiudue<py) = " << (pypiudue<py) << endl;
  cout << "(pypiudue>py) = " << (pypiudue>py) << endl;

  return 0;
}

