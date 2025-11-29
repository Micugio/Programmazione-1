#include <iostream>
using namespace std;

// Consegna: Stampa in sequenza numeri da 0 a n, prima numeri pari in ordine crescente, poi numeri dispari in ordine decrescente.

void funzione (int i, int n) {
    
    if (i>n) {
        return;
    }
    else {
        if (i%2 == 0) {
            cout << i << endl;
            funzione (i+1, n);
        }
        else {
            funzione (i+1, n);
            cout << i << endl;
        }
    }
}

int main() {
    int i = 0;
    int n = 0;

    cout << "Inserisci il numero: ";
    cin >> n;

    funzione(i, n);

    return 0;
}