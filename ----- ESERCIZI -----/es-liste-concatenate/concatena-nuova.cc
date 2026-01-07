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

nodo* copia(nodo* s) {
  if (s == NULL) {       // lista originale vuota
    return NULL;
  }

  nodo* testaNuova = NULL;  // testa della nuova lista
  nodo* ultimo = NULL;      // puntatore all'ultimo nodo della nuova lista
  nodo* corrente = s;          // puntatore per scorrere la lista originale

  while (corrente != NULL) {
    // Creo un nuovo nodo
    nodo* nuovo = new nodo;
    nuovo->dato = corrente->dato;
    nuovo->next = NULL;

    if (testaNuova == NULL) {
      // primo nodo: inizializzo la testa della nuova lista
      testaNuova = nuovo;
    } 
    else {
      // collego il nuovo nodo all'ultimo nodo della nuova lista
       ultimo->next = nuovo;
      }

    // aggiorno l'ultimo nodo
    ultimo = nuovo;

    // passo al prossimo nodo della lista originale
    corrente = corrente->next;
  }

  return testaNuova;  // restituisco la testa della nuova lista
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

nodo  * concatena_new(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) {
    return copia(s2);
  }
  if (s2 == NULL) {
    return copia(s1);
  }
  nodo  *cs1 = copia(s1);
  nodo  *cs2 = copia(s2);

  nodo  * p;

  // for (p = cs1; ((p != NULL) && (p->next != NULL)); p = p->next);  NOTA: non serve controllare (p != NULL) già controllato prima con if che s1 (e quindi cs1) != da NULL.
  for (p = cs1; p->next != NULL; p = p->next);

  p->next = cs2;

  return cs1;
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

  // nodo * x = NULL;
  // nodo * y = NULL;

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

/*
  x = copia(L1);
  y = copia(L2);

  x = concatena(x, y);

  cout << "Lista L1:" << endl;
  stampa(L1);

  cout << endl;
  cout << "Lista L2:" << endl;
  stampa(L2);

  cout << endl;

  cout << "Lista x (= x + y):" << endl;
  stampa(x);

  cout << endl;

  cout << "Lista y:" << endl;
  stampa(y);
*/

  k = concatena_new(L1, L2);

  cout << "Lista k (= L1 + L2):" << endl;
  stampa(k);

  delete_list(L1);
  delete_list(L2);
  delete_list(k);

/*
  delete_list(L1);
  delete_list(L2);
  delete_list(x);
  // delete_list(y); 
*/

  return 0;
}