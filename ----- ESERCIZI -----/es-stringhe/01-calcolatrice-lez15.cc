using namespace std;
#include <iostream>
#include <cstdlib>

// CONSEGNA: leggere in input da riga di comando due numeri e un operatore, eseguire il calcolo.

int main (int argc, char * argv[]) {
  
  double risultato, n1, n2;
  char operatore;

  n1 = atof(argv[1]);
  n2 = atof(argv[2]);
  operatore = *(argv[3]);

  if (operatore == '+') {
    risultato = n1 + n2;
  }
  if (operatore == '-') {
    risultato = n1 - n2;
  }
  if (operatore == '*') {
    risultato = n1 * n2;
  }
  if (operatore == '/') {
    risultato = n1 / n2;
  }

  cout << risultato << endl;
  
  return 0;
}
