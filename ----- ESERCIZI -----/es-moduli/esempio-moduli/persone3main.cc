using namespace std;
#include <iostream>
#include "persone3.cc"

int main ()
{
  persona * pos;
  char cognome[NmaxCognome];
  char nome[NmaxNome];
  persona p;
  gruppo g;
  char s[2];

  inizializza_gruppo(g);
  do {
    cout << endl;
    cout << " i: inserisci\n";
    cout << " n: stampa per ordine di nome\n";
    cout << " c: stampa per ordine di cognome\n";
    cout << " o: cerca per nome\n";
    cout << " g: cerca per cognome\n";
    cout << " e: esci\n";
    cout << "\nInserisci Scelta: ";
    cin >> s;

    switch (s[0]) {
    case 'i': leggi_persona(p);
      if (! inserisci_persona_gruppo(p,g))
	cout << "Gruppo pieno\n";
      break;
    case 'n': stampa_gruppo_per_nome (g); break;
    case 'c': stampa_gruppo_per_cognome (g); break;
    case 'o': leggi_nome(nome);
      pos=cerca_per_nome(nome,g);
      if (pos==NULL)
	cout << "Non trovato\n";
      else {
	cout << "Trovato: "  << endl;
	stampa_persona(*pos);
      }
      break;
    case 'g': leggi_cognome(cognome);
      pos=cerca_per_cognome(cognome,g);
      if (pos==NULL)
	cout << "Non trovato\n";
      else {
	cout << "Trovato: "  << endl;
	stampa_persona(*pos);
      }
      break;
    case 'e': break;
    default: cout << "scelta non capita\n";
    }
  }
  while ((s[0]=='i' || s[0]=='n' || s[0]=='c' || s[0]=='o' || s[0]=='g'));
}
