#include <iostream>
using namespace std;

void binario (int n) {
    if (n==0) {
        cout << "0" << endl;
        return;
    }
    if (n==1) {
        cout << "1" << endl;
        return;
    }
    cout << n%2;
    binario(n/2);
}

int main() {
    int n = 0;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    binario(n);
    cout << endl;

    return 0;
}

// LA MIA VERSIONE (non funziona)

/*

void funzione (int n, int k, int binario) {
    
    if (n>=2) {
        binario = n/2;
        n = n%2;
        funzione (n, k, binario);
        cout << binario << endl;
        return;
    }
    else {
        cout << k << endl;
        return;
    }
}

int main() {
    int n = 0;
    int k = 0;
    int binario = 0;

    cout << "Inserisci il numero: ";
    cin >> n;

    funzione(n, k, binario);

    return 0;
}

*/