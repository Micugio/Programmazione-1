using namespace std;
#include <iostream>

// CURIOSITÀ: se stampa &v, stamperò l'indirizzo di v[0] perchè v è un puntatore con valore l'indirizzo del primo elemento dell'array
int main () {
  const int dim = 4;
  int v[dim] = {10,20,30,40};
  int *p = v; // NOTA: scrittura corretta, perchè v è un puntatore con valore l'indirizzo del primo elemento dell'array (v[0]).  QUINDI: p punta a v[0].
  cout << " v = " << (long) v << endl;
  for (int i=0;i<dim;i++)
    cout << " i = " << i <<
            " , &v[i] = " << (long) &p[i] << // &v[i] == &p[i]      QUINDI: &v[i] == v+i == &p[i] == p+i
            " , v+i = " << (long) (p+i) <<   // v+i == p+i
            " , v[i] = " << p[i] <<
            " , *(v+i) = " << *(p+i) <<
            "   ,   &v = " << (long) &v << endl; // stampa SEMPRE indirizzo di v[0]
  
  return 0;
}
