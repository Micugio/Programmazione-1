#include <iostream>
using namespace std;

/*
ESERCIZIO 4 (Tutorato 29/09/2025):
CONSEGNA: stamparei primi 20 numeri della serie di Fibonacci
Esempio di serie di Fibonacci: 0 1 1 2 3 5 8 13
Regola serie di Fibonacci:  F0 = 0
                            F1 = 1
                            F_n = F_{n-1} + F_{n-2}
*/

// SPIEGAZIONE: Con Fibonacci un numero si ottiene con la somma dei 2 numeri precedenti, quindi ci voglione 3 variabili che si scambiano il varole "scorrendolo" ad ogni ciclo.
int main() {
    int n = 20; // Quantità di numeri che voglio stampare
    int a = 0;  // Primo numero
    int b = 1;  // Secondo numero
    int c = 0;  // Somma dei due numeri precedenti (a e b)

    cout << "I primi " << n << " numeri della serie di Fibonacci:" << endl;

    for (int i = 0; i < n; i++) {
        if (i==0) {
            cout << a << " ";
        }
        if (i==1) {
            cout << b << " ";
        }
        if (i!=0 && i!=1) {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
            c = 0;
        }
    }

    cout << endl;

    return 0;
}
