#include <iostream>
using namespace std;

// Consegna: Stampa in sequenza numeri da 0 a n.

void funzione (int i, int n) {
    
    if (i>n) { // Caso in cui i == n
        return; // Si può anche non mettere (serve solo per capire il concetto)
    }
    else { // Caso in cui a < n
        cout << i << endl;
        funzione (++i, n);
        return;
    }
    //cout << a << endl;  //Da usare quando voglio stampare numeri in ordine decrescente
}

int main() {
    int i = 0;
    int n = 0;

    cout << "Inserisci il numero: ";
    cin >> n;

    funzione(i, n);

    return 0;
}