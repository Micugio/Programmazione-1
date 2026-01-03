#include <iostream>
#include <fstream>
#include <cmath>
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

bool primalita (int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void primizzaLista (nodo * & s) {
  nodo * q = s;
  while(q != NULL) {
    if (!(primalita(q->dato))) {
      remove_element(s, q->dato);
      q = s;
    }
    else {
      q = q->next;
    }
  }
}

/*
void primizzaLista (nodo * & p) {
  if (p != NULL) {
    nodo* q = p;
    if (!(primalita(q->dato))) {
      p = p->next;
      delete q;
    }
    else {
      while(q->next != NULL) {
        if (!(primalita(q->next->dato))) {
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
*/

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

  nodo * x = NULL;

  int value = 0;

  //int n = 11;


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
    insert_last(x, value);
  }

  /*
  for (int i = 1; i < 6; i++) {
    value = rand() % 20;
    insert_last(x, value);
  }
  */

  cout << "La lista creata è:" << endl;
  stampa(x);

  
  primizzaLista(x);
  cout << "La lista con SOLO numeri primi è:" << endl;
  stampa(x);

  return 0;
}
