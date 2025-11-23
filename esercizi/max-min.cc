#include <iostream>
using namespace std;

/*
NOTA:
Se inizializzo variabile senza assegnarli valore fuori main è una variabile globale con valore = 0.
Se inizializzo variabile dentro main senza assegnarli valore non so quale valore assume.
QUINDI assegna sempre valore a variabile inizializzata.
*/

int main() {

    int a, b, max, min;

    cout << "Inserisci il valore di a: " << endl;
    cin >> a;
    cout << "Inserisci il valore di b: " << endl;
    cin >> b;

    max = a*(a>=b)+b*(a<b);
    // Alternativa: min = a*(a<=b)+b*(a>b);
    min = (a+b)-max;

    cout << "Il massimo è: " << max << endl;
    cout << "Il minimo è: " << min << endl;
    
    return 0;
}