#include "structstack.h"

static bool emptyp (const stack & s)
{
  return (s.indice==0);
}

static bool fullp (const stack & s)
{
  return (s.indice==dim);
}

/*
// Implementazione statica ////
void init (stack & s)
{
  s.indice = 0;
}

void deinit (stack & s)
{
}
///////////////////////////
*/

// Implementazione dinamica ////
void init (stack & s)
{
  s.indice = 0;
  s.elem = new int[dim];
}

void deinit (stack & s)
{
  delete [] s.elem;
}
///////////////////////////

retval top (int & n, const stack & s)
{
  retval res;
  if (emptyp(s))  // Se pila è VUOTA return FAIL (impossibile "LEGGERE" ultimo elemento inserito)
    res = FAIL;
  else {
    n=s.elem[s.indice-1]; // n = ultimo elemento della pila (cioè l'unico a cui posso accedere)
    res = OK;
  }
  return res;
}

retval push (int n, stack & s)
{
  retval res;
  if (fullp(s))  // Se pila è PIENA return FAIL (impossibile INSERIRE elemento sulla pila)
    res = FAIL;
  else {
    s.elem[s.indice]=n;  // ATTENTO! (s.elem[s.indice] = n) DIVERSO DA (n = s.elem[s.indice])
    s.indice++;
    res = OK;
  }
  return res;
}

// RICORDA: con la pop e la memoria dinamica devo SEMPRE fare la delete (vedi riga 45 file structstackmain.cc)
retval pop (stack & s)
{
  retval res;
  if (emptyp(s))  // Se pila è VUOTA return FAIL (impossibile RIMUOVERE ultimo elemento inserito)
    res = FAIL;
  else {
    s.indice--;
    res = OK;
  }
  return res;
}

void print(const stack & s)
{
  int i;
  for (i=0;i<s.indice;i++)
    cout << s.elem[i] << " ";
  cout << endl;
}
