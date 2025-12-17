using namespace std;
#include <iostream>
#include <cstring>
#include "persone3.h"

//  DEFINIZIONE FUNZIONI

void leggi_indirizzo (address &a)
{
  cout << "\n Inserisci via: ";
  cin >> a.via;
  cout << "\n Inserisci civico: ";
  cin >> a.civico;
  cout << "\n Inserisci comune: ";
  cin >> a.comune;
  cout << "\n Inserisci cap: ";
  cin >> a.cap;
  cout << "\n Inserisci prov: ";
  cin >> a.prov;
}

void stampa_indirizzo (address & a)
{
  cout << "Via: " << a.via << endl;
  cout << "Civico: " << a.civico << endl;
  cout << "Comune: " << a.comune << endl;
  cout << "cap: " << a.cap << endl;
  cout << "prov: " << a.prov << endl;
  cout << endl;
}

void leggi_nome (char s[])
{
  cout << "\n Inserisci nome: ";
  cin >> s;
}

void stampa_nome (char s[])
{
  cout << "nome: " << s << endl;
}

void leggi_cognome (char s[])
{
  cout << "\n Inserisci cognome: ";
  cin >> s;
}

void stampa_cognome (char s[])
{
  cout << "cognome: " << s << endl;
}

void leggi_persona(persona & p)
{
  leggi_nome(p.nome);
  leggi_cognome(p.cognome);
  leggi_indirizzo(p.indirizzo);
}

void stampa_persona(persona & p)
{
  stampa_nome(p.nome);
  stampa_cognome(p.cognome);
  stampa_indirizzo(p.indirizzo);
}

void inizializza_gruppo (gruppo &g)
{
  g.npers=0;
}

bool inserisci_persona_gruppo (const persona & p, gruppo & g)
{
  bool res = true;
  if (g.npers==NmaxPers)
    res = false;
  else {
    persona * tmp;
    tmp = new(persona);
    *tmp = p;
    g.nomi[g.npers] = tmp;
    g.cognomi[g.npers] = tmp;
    g.npers++;
    ordina_per_nome(g.nomi,g.npers);
    ordina_per_cognome(g.cognomi,g.npers);
  }
  return res;
}

void stampa_gruppo_per_nome (gruppo & g)
{
  stampa_persone(g.nomi,g.npers);
}

void stampa_gruppo_per_cognome (gruppo &  g)
{
  stampa_persone(g.cognomi,g.npers);
}


void stampa_persone(persona *p[], int n)
{
  int i;
  for   (i=0; i < n; i++) {
    stampa_persona(*p[i]);
  }
}

void swap (persona *&p1, persona *&p2)
{
  persona * temp;
  temp=p1; p1=p2; p2=temp;
}

//procedura di bubble sort, per nome
void ordina_per_nome(persona *p[], int n)
{
  int i, j;

  for (i=n-1; i > 0; i--)
    for (j=0; j< i; j++)
      if (strcmp(p[j]->nome,p[j+1]->nome)> 0)
        swap(p[j],p[j+1]);
}


//procedura di bubble sort, per cognome
void ordina_per_cognome(persona *p[], int n)
{
  int i, j;

  for (i=n-1; i > 0; i--)
    for (j=0; j< i; j++)
      if (strcmp(p[j]->cognome,p[j+1]->cognome)> 0)
        swap(p[j],p[j+1]);
}

persona * cerca_per_nome(char nome[],gruppo g)
{
  return cerca_per_nome1(nome,g.nomi,0,g.npers-1);
}

//procedura di ricerca dicotomica, per nome
persona * cerca_per_nome1(char nome[],persona *p[],int inizio,int fine)
{
  int pivot,cmp;
  persona * res;
  if (inizio > fine)
    res = NULL;
  else {
    pivot = (inizio+fine)/2;
    cmp =  strcmp(p[pivot]->nome,nome);
    if (cmp==0)
      res = p[pivot];
    else if (cmp>0)
      res = cerca_per_nome1(nome,p,inizio,pivot-1);
    else
      res = cerca_per_nome1(nome,p,pivot+1,fine);
  }
  return res;
}

persona * cerca_per_cognome(char cognome[],gruppo g)
{
  return cerca_per_cognome1(cognome,g.cognomi,0,g.npers-1);
}



//procedura di ricerca dicotomica, per cognome
persona * cerca_per_cognome1(char cognome[],persona *p[],int inizio,int fine)
{
  int pivot,cmp;
  persona * res;
  if (inizio > fine)
    res = NULL;
  else {
    pivot = (inizio+fine)/2;
    cmp =  strcmp(p[pivot]->cognome,cognome);
    if (cmp==0)
      res = p[pivot];
    else if (cmp>0)
      res = cerca_per_cognome1(cognome,p,inizio,pivot-1);
    else
      res = cerca_per_cognome1(cognome,p,pivot+1,fine);
  }
  return res;
}
