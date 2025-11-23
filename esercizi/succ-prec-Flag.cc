#include <iostream>
using namespace std;

/*
NOTA:
Se inizializzo variabile senza assegnarli valore fuori main è una variabile globale con valore = 0.
Se inizializzo variabile dentro main senza assegnarli valore non so quale valore assume.
QUINDI assegna sempre valore a variabile inizializzata.
*/

int main() {

    int n, flag, succ, prec;

    cout << "Inserisci il numero: " << endl;
    cin >> n;

    flag = n;

    succ = ++n;
    prec = --flag;

    cout << "Numero successivo: " << succ << endl;
    cout << "Numero precedente: " << prec << endl;
    
    return 0;
}