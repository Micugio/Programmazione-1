#include <iostream>
using namespace std;


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};


void insert_last(nodo * & s, int d) {
  nodo * n = new nodo;
  n->dato = d; 
  n->next = NULL;

  // Se la lista e' vuota, allora s dovra' puntare al nuovo nodo
  if (s == NULL) {
    s = n;
  }
  else {
    // Cerco l'ultimo elemento, q->next qui e' lecito perche' siamo
    // sicuri che s e' diverso da NULL
    nodo * q = s;
    while(q->next != NULL) {
      q = q->next;
    }
    // Una volta trovato ultimo elemento campo next punta al nodo nuvo.
    q->next = n;
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

// Stampa contenuto della lista invertito con funzione ricorsiva
void stampa_inverso(nodo * s, int j) {
  if (s == NULL) {
    return;
  }
  else {
    stampa_inverso(s->next, ++j);
    cout << "Elemento " << j << " = " << s->dato << endl;
  }
}


int main() {

  nodo * x = NULL;

  int value = 0;
  int j = 0;

  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(x, value);
  }

  cout << "La lista creata è:" << endl;
  stampa(x);

  cout << "La lista invertita è:" << endl;
  stampa_inverso(x, j);

  return 0;
}
