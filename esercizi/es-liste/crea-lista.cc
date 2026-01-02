#include <iostream>
#include <fstream>
using namespace std;


// ESEGUIRE CON:   ./a.out file.txt


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 0;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

int main(int argc, char * argv[]) {
  fstream myin;

  nodo * Lista = NULL;

  int value = 0;

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=2) {
    cerr << "Usa: ./a.out <fileinput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin, non è mai stato aperto perché è andato in errore
  }

  myin >> value;
  while (!myin.fail()) {
    nodo * t = new nodo;
    t->dato = value; 
    t->next = Lista;
    Lista = t;

  }
  cout << endl;
  cout << "La lista creata è:" << endl;
  stampa(Lista);

  return 0;
}
