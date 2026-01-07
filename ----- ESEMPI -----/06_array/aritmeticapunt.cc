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

  px++; // (cioè +4 , perchè 1*4)
  cout << "px = " << (long) px << endl; 

  cout << endl;
  cout << "---------------------------------" << endl;
  cout << endl;

  cout << "Size(long double) = " << sizeof(long double) << endl;
  cout << "Address(y) = " << (long) &y << endl;
  cout << "py = " << (long) py << endl;
  cout << endl;

  py += 2; // (cioè +32 , perchè +2*16)
  cout << "py = " << (long) py << endl; 

  pypiudue = py; // il puntatore pypiudue punta a y (perchè il puntatore py contiene l'indirizzo di y), quindi modificando valore di pypiudue modifico anche valore di y.
  cout << "pypiudue = " << (long) pypiudue << endl;


  {
    // ESEMPIO di (codice isolato):
    cout << "-------------------------------" << endl;

    int y = 3;
    int* py = &y;
    int* pypiudue;

    cout << "y = " << y << endl;

    pypiudue = py; // pypiudue punta a y (perchè py contiene l'indirizzo di y)
    *pypiudue = 10; // Quindi se modifico valore di pypiudue modifico anche valore di y
    
    cout << "y = " << y << endl; // stampa 10
    cout << "py = " << *py << endl; // stampa 10
    cout << "pypiudue = " << *pypiudue << endl; // stampa 10

    cout << "-------------------------------" << endl;
  }

  py -= 3; // (cioè -48 , perchè -3*16)
  cout << "py = " << (long) py << endl;  
  cout << "pypiudue = " << (long) pypiudue << endl; // Valore non cambia perchè pypiudue non punta a py (ho solo l'indirizzo)

  py +=1; // (cioè +16 , perchè 1*16)
  cout << "py = " << (long) py << endl;

  cout << endl;

  cout << "pypiudue = " << (long) pypiudue << endl; // Valore sempre uguale
  cout << "py =       " << (long) py << endl;
  cout << "pypiudue-py (in long) = " << (long) pypiudue - (long) py << endl; // 140723474874144 - 140723474874112 = 32 -> 2*16 -> 2
  cout << "pypiudue-py (in double) = " << pypiudue - py << endl; // 32 -> 2*16 -> 2
  cout << "py-pypiudue (in long) = " << (long) py - (long) pypiudue << endl; // 140723474874144 - 140723474874112 = 32 -> 2*16 -> 2
  cout << "py-pypiudue (in double) = " << py - pypiudue << endl; // 32 -> 2*16 -> 2
  cout << endl;

  cout << "(pypiudue<py) = " << (pypiudue<py) << endl; // stampa 0 (=false)
  cout << "(pypiudue>py) = " << (pypiudue>py) << endl; // stampa 1 (=true)

  return 0;
}

