#include <iostream>
using namespace std;


// CONSEGNA: Stampa in sequenza numeri da 0 a n, in ordine crescente e decrescente.


/*
// VERSIONE PIÙ CHIARA CONCETTUALMENTE
void stampa_crescente (int n) {
    if (n < 0) {
        return;
    }
    else {
        stampa_crescente(n-1);
        cout << n << " ";
    }
}

// VERSIONE PIÙ CHIARA CONCETTUALMENTE
void stampa_decrescente (int n) {
    if (n < 0) {
        return;
    }
    else {
        cout << n << " ";
        stampa_decrescente(n-1);
    }
}
*/

void stampa_crescente (int n) {
    if (n >= 0) {
        stampa_crescente(n-1);
        cout << n << " ";
    }
}

void stampa_decrescente (int n) {
    if (n >= 0) {
        cout << n << " ";
        stampa_decrescente(n-1);
    }
}


int main() {
    int n = 0;
    
    do {
        cout << "Inserisci un numero positivo: " << endl;
        cin >> n;
    } while (n<0);

    stampa_crescente(n);
    cout << endl;

    stampa_decrescente(n);
    cout << endl;

    return 0;
}
