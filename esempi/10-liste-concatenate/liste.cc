#include <iostream>
using namespace std;

// Struttura lista di interi
struct nodo {
  int dato;
  nodo * next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Calcolo della lunghezza di una lista.
int length(nodo * s) {  // NOTA: SEMPRE passaggio per valore, per riferimento perdo accesso a lista (perchè nodo iniziale s (head) alla fine della funzione punterà a null, cioè avrò una lista vuota senza nodi)
  int result = 0;

  for( ; s != NULL; s = s->next)
    result++;
  return result;
}

// VERSIONE RICORSIVA: Calcolo della lunghezza di una lista.
int length_ric(nodo * s) { // NOTA: passaggio per valore perchè voglio solo contare elementi e non modificare nodo iniziale s (head)
  if (nullptr == s) {
    return 0;
  }
  return 1 + length_ric(s->next);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA 1: Dealloca la memoria della lista (NOTA: uso passaggio per riferimento).
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
/*
// VERSIONE ITERATIVA 2: Dealloca la memoria della lista (NOTA: uso passaggio per valore).
void delete_list(nodo * s) {    //(passaggio per valore)
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
DOPO funzione DEVO AGGIUNGERE nel main:
s = nullptr;   // Puntatore head diventa nullptr
*/

// VERSIONE RICORSIVA 1: Dealloca la memoria della lista (NOTA: uso passaggio per riferimento).
void delete_list_ric(nodo * & s) {   //(passaggio per riferimento)
  if (s != nullptr) {  // Tutti i casi tranne quando è caso base
    delete_list_ric(s->next);
    delete s;
    s = nullptr;  // Puntatore head diventa nullptr
  }
}
/*
// VERSIONE RICORSIVA 2: Dealloca la memoria della lista (NOTA: uso passaggio per valore).
void delete_list_ric(nodo * s) {
  if (s != nullptr) {
    delete_list_ric(s->next);
    delete s;
  }
}
DOPO funzione DEVO AGGIUNGERE nel main:
s = nullptr;  // Puntatore head diventa nullptr
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Stampa contenuto della lista
void stampa(nodo * s) {
  int i = 0;
  while(s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

// VERSIONE RICORSIVA: Stampa contenuto della lista
void stampa_ric(nodo * s, int i = 0) {
    if (s == NULL) {
      return; // caso base: lista finita
    }
    cout << "Elemento " << i << " = " << s->dato << endl;
    stampa_ric(s->next, i + 1); // passo al nodo successivo incrementando l'indice
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: 
void insert_last(nodo * & s, int d) {
  nodo * n = new nodo;
  n->dato = d; 
  n->next = NULL;

  // Se la lista e' vuota, allora s dovra' puntare al nuovo nodo
  if (s == NULL) {
    s = n;
  }
  else {
    // Cerco l'ultimo elemento, q->next qui e' lecito perche' siamo sicuri che s e' diverso da NULL
    nodo * q = s;
    while(q->next != NULL) {
      q = q->next;
    }
    // Una volta trovato ultimo elemento campo next punta al nodo nuvo.
    q->next = n;
  }
}

// VERSIONE RICORSIVA: 
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// NOTA: è già una funzione ricorsiva!
void insert_first(nodo * &s, int d) {
  // Creo il nuovo nodo e memorizzo il valore utilizzando costruttore
  // ad un solo argomento
  nodo * n = new nodo;
  n->dato = d;
  // Il campo next di n punta a s
  n->next = s;
  // s punt a nuovo nodo n
  s = n;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Inserisce un nodo contenente un valore (d) mantenendo l'ordine della lista (NOTA: da usare su liste ordinate).
void insert_order(nodo * & s, int d) {
  if ((s == NULL) || (s->dato >= d)) {
    // s->dato e' lecito. Se arrivo qui vuol dire che primo disgiunto
    // era falso, e quindi s diverso da NULL
    insert_first(s, d);
  }
  else {
    nodo * q = s;

    while((q->next != NULL) && (q->next->dato <= d)) {
      // Qui siamo sicuri che q != NULL, inoltre se prima condizione
      // e' soddisfatta possiamo accedere al campo dato del nodo
      // successvo. Infatti e' diverso da NULL
      q = q->next;
    }
    nodo * r = new nodo;
    r->dato = d; r->next = q->next;
    q->next = r;
  }
}

// VERSIONE RICORSIVA: Inserisce un nodo contenente un valore (d) mantenendo l'ordine della lista (NOTA: da usare su liste ordinate).
void insert_order_ric(nodo*& s, int d) {
  // caso base: inserimento in testa
  if (s == NULL || s->dato >= d) {
    insert_first(s, d);  // NOTA: insert_first è già una funzione ricorsiva!
    return;
  }

  // caso ricorsivo: avanzo nella lista
  insert_order_ric(s->next, d);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// NOTA: è già una funzione ricorsiva!
void remove_first(nodo * & s) {
  if (s != NULL) {
    nodo * t = s;
    s = s->next;
    delete t;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Rimuove il nodo che contiene il valore cercato (d).
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

// VERSIONE RICORSIVA: Rimuove il nodo che contiene il valore cercato (d).
void remove_element_ric(nodo* &p, int d) {
  if (p == NULL) return;        // lista vuota, niente da fare

  if (p->dato == d) {           // il nodo corrente è quello da eliminare
    nodo* temp = p;
    p = p->next;              // aggiorno il puntatore alla lista
    delete temp;              // libero la memoria
  } else {
    remove_element_ric(p->next, d); // ricorsione sul prossimo nodo
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Reverse con side effect sulla lista originaria.
nodo * reverse(nodo * x) {
  nodo * t;
  nodo * y = x;
  nodo * r = NULL;

  while ( y != NULL ) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}

// VERSIONE RICORSIVA: Reverse con side effect sulla lista originaria.
// Funzione ausiliaria ricorsivo con accumulatore
nodo* reverse_aux(nodo* x, nodo* r) {
  if (x == NULL) {
    return r;               // caso base: lista finita
  }
  nodo* t = x->next;        // salvo il prossimo nodo
  x->next = r;              // inserisco x in testa all'accumulatore
  return reverse_aux(t, x); // ricorsione sul resto della lista
}

// Funzione principale
nodo* reverse_ric(nodo* x) {
  return reverse_aux(x, NULL);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Costruzione della lista rovesciata costruendo una lista nuova.
nodo * reverse_copia(nodo * x) {
  nodo * r = NULL;

  while(x != NULL) {
    nodo * t = new nodo;
    t->dato = x->dato; t->next = r;
    r = t;
    x = x->next;
  }
  return r;
}

// VERSIONE RICORSIVA: Costruzione della lista rovesciata costruendo una lista nuova.
// Funzione ausiliaria con accumulatore
nodo* reverse_copia_aux(nodo* x, nodo* r) {
  if (x == NULL) {
    return r;              // caso base: lista finita, ritorno accumulatore
  }
  nodo* t = new nodo;      // creo copia del nodo corrente
  t->dato = x->dato;
  t->next = r;             // inserisco in testa all'accumulatore
  return reverse_copia_aux(x->next, t); // ricorsione sul resto
}

// Funzione principale
nodo* reverse_copia_ric(nodo* x) {
  return reverse_copia_aux(x, NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Ricerca a e ritorna l'elemento n-esimo se esite.
nodo * get_n(nodo * s, int n) {
  // Se richiedo di prendere elemento con indice negativo ritorno NULL
  if (n < 0) {
    return NULL;
  }
  for(int i = 0; ((i < n) && (s != NULL)); i++) {
    s = s->next;
  }
  // A questo punto se i == n, allora s punta la punto
  // giusto. Altrimenti s punta a NULL e lo possiamo ritornare.
  return s;
}

// VERSIONE RICORSIVA: Ricerca a e ritorna l'elemento n-esimo se esite.
nodo* get_n_ric(nodo* s, int n) {
  if (s == NULL || n < 0) {
    return NULL;                     // lista vuota o indice negativo
  }
  if (n == 0) {
    return s;                        // abbiamo raggiunto il nodo richiesto
  }
  return get_n_ric(s->next, n - 1);  // ricorsione sul nodo successivo
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Ritornare il nodo che precede un nodo x.
nodo * prec(nodo * s, nodo * x) {
  // primo ed unico elemento uguale a x
  if (s == x) return x;
  // primo e unico elemento e' differente da x
  if ((s == NULL) && (s->next == NULL)) return NULL;

  nodo * t = s; // nodo precedente al nodo corrente che sto cercando,
		// inizializzato al primo elemento della lista
  nodo * l = s->next; // nodo che uso per scorrere la lista,
		      // inizializzato al secondo elemento della
		      // lista.

  while((l != NULL) && (l != x)) {
    // Modifico l e t per rispettare il loro significato, ovvero che t
    // punta l nodo che precede l
    t = l;
    l = l->next;
  }
  // raggiunto ultimo elemento e non c'e' nulla
  if (l == NULL) return NULL;
  return t;
}

// VERSIONE RICORSIVA: Ritornare il nodo che precede un nodo x.
nodo* prec_ric(nodo* s, nodo* x) {
    if (s == NULL || s->next == NULL) {
        // Lista vuota o ultimo elemento senza successivo
        return NULL;
    }
    if (s->next == x) {
        // Il prossimo nodo è x, quindi s è il precedente
        return s;
    }
    // Ricorsione sul nodo successivo
    return prec_ric(s->next, x);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA: Concatena due liste.
nodo  * concat_se_iterativa(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  if (s2 == NULL) return s1;

  nodo  * p = s1;

  while((p != NULL) && (p->next != NULL))
    p = p->next;

  p->next = s2;

  return s1;
}

// VERSIONE RICORSIVA: Concatena due liste.
nodo  * concat_se_ricorsiva(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return s2;
  s1->next = concat_se_ricorsiva(s1->next, s2);
  return s1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE RICORSIVA: Duplica una lista
nodo  * copy_seq(nodo  * s) {
  if (s == NULL) {
    return NULL;   // caso base: lista vuota
  }
  else {
    nodo* t = new nodo;
    t->dato = s->dato;
    t->next = copia(s->next);  // collegamento al ritorno
    return t;                  // ritorna SEMPRE la testa
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// VERSIONE ITERATIVA:
nodo  * concat_nose(nodo  * s1, nodo  * s2) {
  if (s1 == NULL) return copy_seq(s2);
  if (s2 == NULL) return copy_seq(s1);

  nodo  *cs1 = copy_seq(s1);
  nodo  *cs2 = copy_seq(s2);

  nodo  * p;

  for(p = cs1; ((p != NULL) && (p->next != NULL)); p = p->next);

  p->next = cs2;

  return cs1;
}

// VERSIONE RICORSIVA:
nodo  * concat_nose_recur(nodo  *s1, nodo  *s2) {
  if (s1 == NULL) return copy_seq(s2);

  nodo * t = new nodo;
  t->dato = s1->dato;
  t->next = concat_nose_recur(s1->next, s2);
  return t;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main() {
  nodo * L1 = NULL;

  for(int i = 0; i < 10; i++) {
    int d = rand()%100;

    cout << "Inserting number " << d << endl;
    nodo * t = new nodo;
    t->dato = d; 
    t->next = L1;
    L1 = t;
  }
  cout << endl;
  cout << "La lista L1 creata e':" << endl;
  stampa(L1);

  cout << endl;

  nodo * L2 = NULL;

  for(int i = 0; i < 20; i++) {
    int d = rand()%100;

    cout << "Inserting number " << d << endl;
    nodo * t = new nodo;
    t->dato = d; 
    t->next = L2;
    L2 = t;
  }
  cout << endl;
  cout << "La lista L2 creata e':" << endl;
  stampa(L2);

  cout << endl;

  // Provare ad inserire qui le funzioni definite prima
  cout << "La lista L1 ha lunghezza: " << length(L1) << endl;
  cout << "La lista L2 ha lunghezza: " << length(L2) << endl;


  // Per eliminare memoria dinamica ed evitare memory leak:
  delete_list(L2);
  delete_list(L1);
}
*/

int main () {
  nodo * x = NULL;

  for (int i = 0; i<5; i++) {
    insert_last_ric(x, i);
  }

  stampa(x);

  return 0;
}