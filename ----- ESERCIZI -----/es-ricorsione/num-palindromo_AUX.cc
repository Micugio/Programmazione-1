#include <iostream>
using namespace std;

// Es. UGUALE a num-palindromo.cc SOLO fatto anche con funzione_aux.

// Funzione tail recursive che inverte il numero originale.
int palindromo_aux (int n, int val) {
    if (n <= 0) {
        return val;
    }
    else {
        val = (val * 10) + (n % 10);
        return palindromo_aux(n/10, val);
    }
}

// Restituisce true o false se il numero invertito è uguale al numero originale (= palindromo).
bool palindromo (int n) {
    int val = 0;
    int palindromo = 0;

    palindromo = palindromo_aux(n, val);
    cout << "(" << palindromo << ")" << endl;

    if (palindromo_aux(n, val) == n) {
        return true;
    }
    else {
        return false;
    }
}



int main() {
    int n = 0;
    bool risposta;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo.
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    risposta = palindromo(n);

    if (risposta) {
        cout << "Il numero É palindromo!" << endl;
    }
    else {
        cout << "Il numero NON è palindromo!" << endl;
    }

    return 0;
}
