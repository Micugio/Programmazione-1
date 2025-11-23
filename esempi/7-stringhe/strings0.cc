#include <iostream>
using namespace std;

// NOTA: Dopo aver compilato file usare:  ./a.out < testo1.txt

int main() {
  int DIM = 50; // Numero limite di caratteri contenuti nella singola parola, siccome cin legge una parola per volta perchè ci sono in mezzo gli spazi
  char word[DIM];
  
  cin >> word;
  cout << word << endl;
  
  return 0;
}
