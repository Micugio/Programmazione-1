#include <iostream>

using namespace std;

// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};

// Crea un nodo e lo inserisce in fondo
void insert_node (nodo * x, nodo * t) {
  t->next = x->next;
  x->next = t;
}

// Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 0;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

int main() {
  
  nodo *x = new nodo;
  cout << "Inserire_numero: ";
  cin >> x->dato;
  x->next = NULL;
  
  for (int i = 0; i < 5; i++) {
    nodo *t = new nodo;
    cout << "Inserire_un_numero: ";
    cin >> t->dato;
    t->next = NULL;
    insert_node(x, t);
  }

  // Stampa valori della lista
  for (nodo *s = x; s != NULL; s = s->next) {
    cout << "valore= " << s->dato << endl;
  }
  
  //stampa(x);

  return 0;
}
