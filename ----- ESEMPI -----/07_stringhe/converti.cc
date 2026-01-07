using namespace std;
#include <iostream>
#include <cstdlib>
#include <iomanip>

int main () 
{
  const float euro = 1936.27;

  int value;
  float liravalue;
  
  // Questo programma richiede un separatore dopo l'ultimo elemento letto
  // altrimenti meglio usare !cin.fail()
  // NOTA: "!cin.eof()" va usato sempre *DOPO* almeno un'operazione di lettura
  cin >> value;
  while (!cin.eof()) { // while in loop, se stassi leggendo da file si fermerebbe se i dati che stai leggendo finiscono
    liravalue = euro*value;
    cout << value << " "  << fixed << setw(8) << setprecision(0) 
         << liravalue << endl;
    cin >> value;
  }

  // Fai comando CTRL + D sulla tastiera (= fine input, quindi ciclo while diventa false e esce dal ciclo)
  cout << "Fine programma!";

  return 0;
}
