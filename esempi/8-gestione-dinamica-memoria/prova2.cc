using namespace std;
#include <iostream>
#include <cctype>
#include <cstring>
 
int main () 
{
  const int dim = 20; // (dim - 1 = 19) -> Dimensione massima per ogni parola, perchè uso come input "cin" e non "cin.getline()"
  int *p;
  char * sa = new char [dim];
  char * sb = new char [dim];
  char *sc;
  //cin >> sc; // errore: non allocata!
  do {
    cin >> sa >> sb;
    sc = new char[strlen(sa)+strlen(sb)+1]; // strlen = lunghezza stringa -1 (terminatore)
    strcpy(sc,sa);
    strcat(sc,sb);
    cout << sc << endl;
    delete [] sc;
  } while (isalnum(sa[0])); // Ciclo si ferma se il primo carattere della stringa "sa" non è un carattere alfanumerico (viene dalla libreria <cctype>)
  delete [] sa; 
  delete [] sb;
return 0; 
}

