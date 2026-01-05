#include <iostream>
#include <cstdlib>
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

nodo* copia(nodo * s) {
  if (s == NULL) {
    return NULL;   // caso base: lista vuota
  }
  else {
    nodo* t = new nodo;
    t->dato = s->dato;
    t->next = copia(s->next);  // collegamento al ritorno
    return t;                  // ritorna SEMPRE la testa
  }
}

void stampa_ric(nodo * s, int i = 0) {
    if (s == NULL) {
      return; // caso base: lista finita
    }
    cout << "Elemento " << i << " = " << s->dato << endl;
    stampa_ric(s->next, i + 1); // passo al nodo successivo incrementando l'indice
}


int main() {

  nodo * L1 = NULL;
  nodo * L2 = NULL;

  int value = 0;

  srand(time(NULL));

  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last_ric(L1, value);
  }

  cout << "Lista L1:" << endl;
  stampa_ric(L1);

  L2 = copia(L1);
  cout << "Lista L2:" << endl;
  stampa_ric(L2);



  return 0;
}