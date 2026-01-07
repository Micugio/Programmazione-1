using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

// CONSEGNA: leggere una frase un file in input da riga di comando e stampare su terminale di output ogni parola invertita.

// ESEGUIRE CON:   ./a.out es6-frase.txt

int main (int argc, char * argv[]) {
  fstream myin;
  
  char ch;
  char str[100];
  int k = 0;

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=2) {
    cerr << "Usa: ./a.out <fileinput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin1, non è mai stato aperto perché è andato in errore
  }

  while (myin.get(ch)) {
    if (ch != ' ') {
    str[k] = ch;
    k++;
    }
    else {
      while (k != 0) {
        cout << str[--k];
      }
      cout << " ";
    }
  }
  
  // Se dopo l'ultima parola non c'è uno spazio:
  if (k != 0) {
    while (k != 0) {
      cout << str[--k];
    }
  }
  cout << endl;

  myin.close();

  return 0;
}
