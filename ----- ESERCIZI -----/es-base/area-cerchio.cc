#include <iostream>
using namespace std;

int main() {
  // Inizializzazione variabili
  float raggio, circonferenza, area;
  const float pigreco = 3.1415;

  // Input utente
  cout <<"Inserisci il raggio: ";
  cin >> raggio;

  // Eseguo calcoli
  circonferenza = 2*pigreco*raggio;
  area = pigreco*(raggio*raggio);

  // Risultati
  cout <<"La circonferenza è: " << (int) circonferenza << endl;
  cout <<"L'area è: " << (int) area << endl;

  return 0;
}
