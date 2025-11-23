#include <iostream>
using namespace std;

/*
NOTA:
Se inizializzo variabile senza assegnarli valore fuori main è una variabile globale con valore = 0.
Se inizializzo variabile dentro main senza assegnarli valore non so quale valore assume.
QUINDI assegna sempre valore a variabile inizializzata.

CONSEGNA: Scrivere il valore assoluto dell'operazione (a-b).
*/

int main() {

    int a=0;
    int b=0;

    cout << "Inserisci il valore di a: " << endl;
    cin >> a;

    cout << "Inserisci il valore di b: " << endl;
    cin >> b;

    int valore_assoluto = (a-b)*((a>=b)-(b>a));
    cout << "Ecco valore assoluto: " << valore_assoluto << endl;
    
    return 0;
}