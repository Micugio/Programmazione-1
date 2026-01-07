#include <iostream>
#include <cstdlib>
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

/*
nodo  * concatena(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  if (s2 == NULL) return s1;

  nodo  * p = s1;

  while((p != NULL) && (p->next != NULL)) {
    p = p->next;
  }

  p->next = s2;

  return s1;
}
*/

void concatena(nodo * & s1, nodo * & s2) {
  if (s1 == NULL) {
    // Se s1 è vuoto, s1 diventa tutta la lista s2
    s1 = s2;
  } 
  else {
    // Scorro fino all'ultimo nodo di s1
    nodo * p = s1;
    while (p->next != NULL) {
      p = p->next;
    }
    // Collego s2 alla fine di s1  (NOTA: funziona anche nel caso in cui s2 è vuota)
    p->next = s2;
  }

  // Ora L2 non deve più essere accessibile
  s2 = NULL;
}

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 1;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

void delete_list(nodo * & s) {   // Passaggio per riferimento
  // Alla fine la lista e' vuota.
  while(s != NULL) {
    // Salvo il valore del nodo corrente
    nodo * t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}


int main() {

  nodo * L1 = NULL;
  nodo * L2 = NULL;

  int value = 0;

  srand(time(NULL));

  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(L1, value);
  }

  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(L2, value);
  }

  cout << "Lista L1:" << endl;
  stampa(L1);

  cout << endl;
  cout << "Lista L2:" << endl;
  stampa(L2);

  cout << endl;

  // L1 = concatena(L1, L2);

  concatena(L1, L2);

  cout << "Lista L1 (= L1 + L2):" << endl;
  stampa(L1);

  cout << endl;

  // NON FA NIENTE perché L2 = NULL (vuota)
  cout << "Lista L2:" << endl;
  stampa(L2);

  delete_list(L1);

  return 0;
}