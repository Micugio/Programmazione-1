#include <iostream>
#include <fstream>
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
// FUNZIONE SBAGLIATA
bool occorre (nodo * s, int n) {
  while (s != NULL) {
    if (s->dato == n) {
      return true;
    }
    else {
      s = s->next;
      if (s->dato == n) { // ERRORE QUI: ad ogni ciclo controllo due nodi però condizione while vale solo per un nodo, se arrivo a ultimo nodo va in crash.
        return true;
      }
    }
  }
  return false;
}
*/

//Funzione cerca se un valore è presente nella lista, in caso affermativo restituisce true altrimenti false.
bool occorre (nodo * s, int n) {
  while (s != NULL) {
    if (s->dato == n) {
      return true;
    }
    else {
      s = s->next;
    }
  }
  return false;
}

// Funzione cerca un valore nella lista, se lo trova restituisce il valore precedente.
int determina (nodo * s, int n) {
  while (s != NULL) {
    if (s->dato == n) {
      return n;
    }
    else {
      if (s->next->dato == n) {
        return s->dato;
      }
      s = s->next;
    }
  }
  return 0;
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

  nodo * x = NULL;

  int value = 0;

  int n = 0;
  int ris = 0;
  bool condizione;

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

  cout << "La lista creata è:" << endl;
  stampa(x);


  cout << "Valore target: ";
  cin >> n;

  condizione = occorre(x, n);

  if (condizione) {
    cout << "Sì, il valore è presente nella lista!" << endl;
    ris = determina(x, n);
    cout << "Ecco il valore precedente al target è: " << ris << endl;
  }
  else {
    cout << "No, il valore non è presente nella lista!" << endl;
  }


  return 0;
}
