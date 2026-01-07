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

nodo  * copia_ric(nodo  * s) {
  if (s == NULL) {
    return NULL;   // caso base: lista vuota
  }
  else {
    nodo* t = new nodo;
    t->dato = s->dato;
    t->next = copia_ric(s->next);  // collegamento al ritorno
    return t;                      // ritorna SEMPRE la testa, perchè dopo il ritorno di tutta la ricorsione t punta alla testa
  }
}

nodo  * concatena_new_ric(nodo  *s1, nodo  *s2) {
  if (s1 == NULL) {
    return copia_ric(s2);
  }

  nodo * t = new nodo;
  t->dato = s1->dato;
  t->next = concatena_new_ric(s1->next, s2);
  return t;
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
  nodo * k = NULL;

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

  k = concatena_new_ric(L1, L2);
  cout << "Lista k (= L1 + L2):" << endl;
  stampa(k);

  delete_list(L1);
  delete_list(L2);
  delete_list(k);

  return 0;
}