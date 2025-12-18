using namespace std;
#include <iostream>

#include "structstack.h"


static bool emptyp (const stack & s) {
  return (s == NULL);
}

void init(stack & s) {
  s = NULL;
}

retval top (int &n,const stack & s) {
  retval res;
  if (emptyp(s))
    res=FAIL;
  else {
    n=s -> val;
    res=OK;
  }
  return res;
}


// memo: "new (nothrow) ..." restituisce NULL
// senza generare eccezioni se l'allocazione non va a buon fine
retval push (int n,stack & s) {
  retval res;
  nodo * np = new (nothrow) nodo; // NOTA: PILE implementate con LISTE sono PIENE solo quando NON c'è più SPAZIO nella memoria dinamica (non c'è funzione per controllare)
  if (np==NULL)
    res = FAIL;
  else {
    np -> val = n;
    np -> next = s;
    s = np;
    res = OK;
  }
  return res;
}

retval pop (stack & s) {
  retval res;
  if (emptyp(s))
    res=FAIL;
  else {
    nodo *first = s;
    s = s -> next;
    delete first; 	// liberare la memoria: cancella
    res=OK;             // l'oggetto puntato da first
  }
  return res;
}

// Per fare la print passo come costante lo stack s (s = puntatore al primo nodo dello stack quindi a tutta la lista concatenata)
// così non viene modificato il valore.
// Creo un nuovo puntatore first (non serve allocarlo è un PUNTATORE) per scorrere la lista e stampare i valori.
// NOTA: Non posso scorrere la lista con il puntatore s perchè a fine scorrimento avrei s==NULL perdendo così l'accesso alla lista.
void print (const stack & s)
{
  nodo *first = s;
  while (first!=NULL) {
    cout << first->val << endl;
    first = first -> next;
  }
}

void deinit(stack & s) {
  while (!emptyp(s))
    pop(s);
}
