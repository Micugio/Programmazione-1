#include <iostream>
using namespace std;

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
*/

void stampa (int i, int n) {
    if (i == n) {
        return;
    }
    else {
        cout << i << " ";
        
        stampa(i+1, n);
    }
}

int main() {
    int n = 0;
    int i = 0;
    
    do {
        cout << "Inserisci un numero positivo: " << endl;
        cin >> n;
    } while (n<0);

    stampa(i, n);
    cout << endl;

    return 0;
}
