#ifndef PERSONE3_H
#define PERSONE3_H

using namespace std;
#include <iostream>

//  INIZIALIZZAZIONE COSTANTI
const int NmaxPers = 1000;
const int NmaxNome = 20;
const int NmaxCognome = 30;

//  INIZIALIZZAZIONE STRUTTURE
struct address {
  char via[NmaxNome];
  int civico;
  char comune[NmaxNome];
  int cap;
  char prov[3];
};

struct persona {
  char nome[NmaxNome];
  char cognome[NmaxCognome];
  address indirizzo;
};

struct gruppo {
  int npers;
  persona * nomi [NmaxPers];
  persona * cognomi [NmaxPers];
};

//  DICHIARAZIONE FUNZIONI
void leggi_indirizzo (address &a);
void stampa_indirizzo (const address & a);
void leggi_nome (char s[]);
void stampa_nome (const char s[]);
void leggi_cognome (char s[]);
void stampa_cognome (const char s[]);

void leggi_persona(persona & p);
void stampa_persona(persona & p);
void stampa_persone(persona *p[], int n);

void inizializza_gruppo (gruppo &g);
bool inserisci_persona_gruppo (const persona & p, gruppo & g);
void stampa_gruppo_per_nome (gruppo & g);
void stampa_gruppo_per_cognome (gruppo & g);


void swap (persona &p1, persona &p2);
void ordina_per_nome(persona *p[], int n);
void ordina_per_cognome(persona *p[], int n);
persona * cerca_per_nome(char nome[],gruppo g);
persona * cerca_per_nome1(char nome[],persona *p[],int inizio,int fine);
persona * cerca_per_cognome(char cognome[],gruppo g);
persona * cerca_per_cognome1(char cognome[],persona *p[],int inizio,int fine);

#endif
