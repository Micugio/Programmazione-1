#include <iostream>
#include <fstream>
using namespace std;


// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};


void insert_last_ric(nodo*& s, int d) {
    // caso base: lista vuota → inserisco qui
    if (s == NULL) {
        s = new nodo;
        s->dato = d;
        s->next = NULL;
        return;
    }

    // caso ricorsivo: avanzo verso la coda
    insert_last_ric(s->next, d);
}

// Funzione cerca se un valore è presente nella lista, in caso affermativo restituisce true altrimenti false.
bool occorre_ric(nodo * s, int n) {
  if (s == NULL) {
    return false;
  }
  else {
    if (s->dato == n) {
      return true;
    }
    return occorre_ric(s->next, n);
  }
}

// Funzione cerca un valore nella lista, se lo trova restituisce il valore precedente, se il valore cercato è in testa restituisce il valore in testa.
//    NOTA: copre i casi in cui il valore target è in testa o all'interno della lista,
//          il main e la funzione occorre coprono i casi in cui il valore non è presente nella lista e se la lista è vuota o ha solo un elemento.
int determina_ric(nodo* s, int n) {
  // Caso 0: lista vuota
  if (s == NULL) {
    return 0;
  }

  // Caso 1: valore target in testa
  if (s->dato == n) {
    return s->dato;
  }

  // Caso 2: valore target presente ma non in testa
  if (s->next != NULL) {
    if (s->next->dato == n) {
      return s->dato;
    }
    return determina_ric(s->next, n);
  }

  return 0;
}

// Dealloca la memoria della lista (funzione ricorsiva, passaggio per riferimento)
void delete_list_ric(nodo * & s) {   //(passaggio per riferimento)
  if (s != nullptr) {  // Tutti i casi tranne quando è caso base
    delete_list_ric(s->next);
    delete s;
    s = nullptr;  // Puntatore head diventa nullptr
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
    insert_last_ric(x, value);
  }

  cout << "La lista creata è:" << endl;
  stampa(x);


  cout << "Valore target: ";
  cin >> n;

  condizione = occorre_ric(x, n);

  if (condizione) {
    cout << "Sì, il valore è presente nella lista!" << endl;
    ris = determina_ric(x, n);
    cout << "Ecco il valore precedente al target è: " << ris << endl;
  }
  else {
    cout << "No, il valore non è presente nella lista!" << endl;
  }

  delete_list_ric(x);

  return 0;
}
