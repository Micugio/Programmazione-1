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

  px += 2; // (cioè +8 perchè un sizeof(int)=4)
  cout << "px = " << (long) px << endl; 

  px -= 3; // (cioè -12 , perchè -3*4)
  cout << "px = " << (long) px << endl;

  px++; // (cioè +4 , perchè +1*4)
  cout << "px = " << (long) px << endl; 

  cout << endl;
  cout << "---------------------------------" << endl;
  cout << endl;

  cout << "Size(long double) = " << sizeof(long double) << endl;
  cout << "Address(y) = " << (long) &y << endl;
  cout << "py = " << (long) py << endl;
  cout << endl;

  py += 2; // (cioè +32 , perchè +2*12)
  cout << "py = " << (long) py << endl; 

  pypiudue = py; // Copia l'indirizzo di py (che è l'indirizzo di y) in pypiudue (NOTA: copia SOLO indirizzo, pypiudue non punta a py).
  cout << "pypiudue = " << (long) pypiudue << endl;

  /*
  {
    RIVEREDERE (vedi domanda chatgpt)
    double y = 3.5;
    cout << y << endl;

    
    double* py = &y;
    double* pypiudue;   // pypiudue punta a y

    cout << y << endl;

    pypiudue = py;
  

    *pypiudue = 10.2;
    
    cout << y << endl; // stampa 10.2
    cout << *py << endl; // stampa 10.2
    cout << *pypiudue << endl; // stampa 10.2
  }
  */

  py -= 3; // (cioè -48 , perchè -3*12)
  cout << "py = " << (long) py << endl;  
  cout << "pypiudue = " << (long) pypiudue << endl; // Valore non cambia perchè pypiudue non punta a py (ho solo l'indirizzo)

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

