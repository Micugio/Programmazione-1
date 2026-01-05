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

void remove_element(nodo * & p, int d) {
  if (p != NULL) {
    nodo* q = p;
    if (q->dato == d) {
      p = p->next;
      delete q;
    }
    else {
      while(q->next != NULL) {
        if (q->next->dato == d) {
          nodo* r = q->next;
          q->next = q->next->next;
          delete r;
          return;
        }
        if (q->next != NULL) {
          q=q->next;
        }
      }
    }
  }
}

int massimo (nodo * s) {
  int max = 0;
  while (s != NULL) {
    if (max < s->dato) {
      max = s->dato;
    }
    s = s->next;
  }
  return max;
}

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 1;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}


int main() {

  nodo * x = NULL;

  int value = 0;
  int max = 0;

  srand(time(NULL));

  /*
  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(x, value);
  }
  */
  cout << "Lista x:" << endl;
  stampa(x);


  max = massimo(x);
  cout << "Massimo: " << max << endl;
  cout << endl;

  remove_element(x, max);
  insert_last(x, max);
  
  cout << "Lista x aggiornata:" << endl;
  stampa(x);

  return 0;
}