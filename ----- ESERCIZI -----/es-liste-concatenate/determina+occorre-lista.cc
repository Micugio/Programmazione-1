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
// FUNZIONE SBAGLIATA (occorre)
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

// Funzione cerca se un valore è presente nella lista, in caso affermativo restituisce true altrimenti false.
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

/*
// FUNZIONE SBAGLIATA (determina)
int determina (nodo * s, int n) {
  while (s != NULL) { // NOTA: se aggiungo anche questa condizione (&& s->next != NULL) codice comunque sbagliato se la lista è formata da un solo elemento.
    if (s->dato == n) {
      return n;
    }
    else {
      if (s->next->dato == n) { // ERRORE QUI: se sono all'ultimo nodo e provo ad accedere al dato del nodo successivo va in crash, MANCA controllo (s->next != NULL).
        return s->dato;
      }
      s = s->next;
    }
  }
  return 0;
}
*/

// Funzione cerca un valore nella lista, se lo trova restituisce il valore precedente, se il valore cercato è in testa restituisce il valore in testa.
//    NOTA: copre i casi in cui il valore target è in testa o all'interno della lista,
//          il main e la funzione occorre coprono i casi in cui il valore non è presente nella lista e se la lista è vuota o ha solo un elemento.
int determina(nodo* s, int n) {
  // Caso 1: valore target in testa
  if (s->dato == n) {
    return s->dato;
  }

  // Caso 2: valore target presente ma non in testa
  while (s->next != NULL) {
    if (s->next->dato == n) {
      return s->dato;
    }
    s = s->next;
  }

  // Non dovrebbe mai arrivarci se occorre è stato usato prima
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

  delete_list(x);

  return 0;
}
