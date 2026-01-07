#include <iostream>
using namespace std;

/*
CONSEGNA: 
Calcolare MCD tra 2 numeri interi positivi utilizzando algoritmo di Euclide e una funzione ricorsiva tail recursive.
Algoritmo di Euclide:
    Siano a e b due numeri interi, tali che 0 <= b < a: 
        1) Se b = 0, allora MCD (a,b) = a; 
        2) Se b ≠ 0, calcolare la divisione di a e  b, chiamando q il quoziente e r il resto della divisione;
        3) Porre a = b e b =r;
        4) Ripartire dal punto 1.
*/


/*
// VERSIONE SBAGLIATA (chiamata ricorsiva sbagliata!!!):
// MAI fare assegnazioni nella chiamata ricorsiva, perché (in questo caso) compilatore non segue ordine nell'assegnazione.
int MCD (int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        int r = a % b;
        return MCD(a=b, b=r);
    }
}
*/

// LA MIA VERSIONE FUNZIONANTE:
int MCD (int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        int r = a % b;
        a=b;
        b=r;
        return MCD(a, b);
    }
    
}

/*
// VERSIONE PIÙ COMPATTA:
int MCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return MCD(b, a % b);
    }
}
*/


int main() {
    int a = 0;
    int b = 0;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo.
        cout << "Inserisci due numeri che rispettano questa condizione (0 <= b < a): " << endl;
        cin >> a;
        cin >> b;
    } while (b<0 || b>a); // NOTA: con questa condizione (b<=0 || b>a) accettavo solo valori di b SOLO SE (b>0) e (b>a) INVECE io voglio accettare anche (b==0).

    cout << "MCD = " << MCD(a, b) << endl;

    return 0;
}
