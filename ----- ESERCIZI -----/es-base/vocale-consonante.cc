#include <iostream>
using namespace std;

int main() {
    
    char k;

    cout << "Inserisci una lettera: " << endl;
    cin >> k;

    // Se k è Maiuscola la rende minuscola
    if (k >= 'A' && k <= 'Z') {
        k += 'a'-'A';  // NOTA: So che Maiuscole precedono minuscole, quindi (a > A) INFATTI (a = 97) e (A = 65)
    }

    // Significato condizione: se k è diverso da lettera minuscola ALLORA esegui ciclo in loop fino a quando condizione è FALSA.
    while (!(k >= 'a' && k <= 'z')) {
        cout << "Inserisci una lettera: " << endl;
        cin >> k;
    }

    /*
    While SE NON CONVERTO k da Maiuscola a minuscola
    // Significato condizione: se k è diverso da lettera Maiuscola o minuscola ALLORA esegui ciclo in loop fino a quando condizione è FALSA.
    while (!((k >= 'A' && k <= 'Z') || (k >= 'a' && k <= 'z')) ) {
        cout << "Inserisci una lettera: " << endl;
        cin >> k;
    }
    */


    if (k=='a' || k=='e' || k=='i' || k=='o' || k=='u') {
        cout << "è una vocale" << endl;
    }
    else {
        cout << "è una consonante" << endl;
    }
    return 0;
}