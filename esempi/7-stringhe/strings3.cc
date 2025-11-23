//  Example 7.3, page 189
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996
// MODIFIED BY ROBERTO SEBASTIANI

using namespace std;
#include <iostream>

// NOTA: Dopo aver compilato file usare:  ./a.out < testo1.txt

const int DIM = 80; // Numero limite di caratteri contenuti nella singola parola, siccome cin legge una parola per volta perchè ci sono in mezzo gli spazi
int main()
{
  char word[DIM];
  //cout << word << endl;  // SBAGLIATO, output stampa la stringa ancora prima di leggere da file, 
                           // di conseguenza siccome la stringa non è inizializzata con valori allora stampa valori a caso.
  do {  
    if (cin >> word)
      cout << "\t\"" << word << "\"\n";
    else
      break;
  } while (word[0] != '.'); // Esce dal ciclo e programma si ferma se incontra un punto, però se il punto è attaccato ad una parola non esce dal ciclo.
  return 0;
}
