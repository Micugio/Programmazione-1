#include <iostream>
#include <fstream>
using namespace std;


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};


void insert_last_ric(nodo*& s, int d) {
  // caso base: lista vuota → inserisco qui
  if (s == NULL) {
    s = new nodo;
    s->dato = d;
    s->next = NULL;
    return;
  }

  // caso ricorsivo: avanzo verso la coda
  insert_last_ric(s->next, d);
}

/*
nodo * copia (nodo * s, nodo * t = NULL) {
  //nodo * t = s;
  if (s == NULL) {
    return t;
  }
  else {
    t = new nodo;
    t->dato = s->dato;
    t->next = NULL;
    return copia(s->next);
    t = s;
  }
}
*/

nodo* copia(nodo* s) {
  if (s == NULL) {
    return NULL;   // caso base
  }
  else {
    nodo* t = new nodo;
    t->dato = s->dato;
    t->next = copia(s->next);  // collegamento al ritorno
    return t;                  // ritorna SEMPRE la testa
  }
}

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 1;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}


int main(int argc, char * argv[]) {
  fstream myin;

  nodo * L1 = NULL;
  nodo * L2 = NULL;

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


  while (myin >> value) {
    insert_last_ric(L1, value);
  }

  cout << "Lista L1:" << endl;
  stampa(L1);

  L2 = copia(L1);
  cout << "Lista L2:" << endl;
  stampa(L2);

  return 0;
}
