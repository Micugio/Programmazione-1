using namespace std;
#include <iostream>
#include <cctype>
#include <cstring>
 
int main () 
{
  const int dim = 20; // (dim-1 = 19) -> Dimensione massima per ogni parola, perchè uso come input "cin" e non "cin.getline()"
  int *p;
  char * sa = new char [dim];
  char * sb = new char [dim];
  char *sc;
  //cin >> sc; // errore: non allocata!
  do {
    cin >> sa >> sb;
    sc = new char[strlen(sa)+strlen(sb)+1]; // strlen = lunghezza stringa -1 (cioè il terminatore).   QUINDI: +1 così è una vera stringa con terminatore.
    strcpy(sc,sa); // COPIA la stringa "sa" in stringa "sc"
    strcat(sc,sb); // COPIA IN CODA alla stringa "sc" la stringa "sb"
    cout << sc << endl;
    delete [] sc;
  } while (isalnum(sa[0])); // Ciclo si ferma se il primo carattere della stringa "sa" non è un carattere alfanumerico (isalnum viene dalla libreria <cctype>)
  delete [] sa; 
  delete [] sb;
return 0; 
}

