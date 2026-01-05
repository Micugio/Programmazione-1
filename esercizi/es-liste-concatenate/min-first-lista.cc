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

void insert_first(nodo * & s, int d) {
  // Creo il nuovo nodo e memorizzo il valore utilizzando costruttore
  // ad un solo argomento
  nodo * n = new nodo;
  n->dato = d;
  // Il campo next di n punta a s
  n->next = s;
  // s punt a nuovo nodo n
  s = n;
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

int minimo (nodo * s) {
  int min = s->dato;
  while (s != NULL) {
    if (min > s->dato) {
      min = s->dato;
    }
    s = s->next;
  }
  return min;
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
  int min = 0;

  srand(time(NULL));

  /*
  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(x, value);
  }
  */
  cout << "Lista x:" << endl;
  stampa(x);


  min = minimo(x);
  cout << "Minimo: " << min << endl;
  cout << endl;

  remove_element(x, min);
  insert_first(x, min);
  
  cout << "Lista x aggiornata:" << endl;
  stampa(x);

  return 0;
}