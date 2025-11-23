#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int i, j, d, n;
    cout << "Inserisci n: ";
    cin >> n;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++){
            d = (int)(i==j); // stampa 1 sulla diagonale
                             // == da risultato buleano (true o false) allora gli metto davanti (int) così mi da (1 o 0)
            cout << d;
        }
        cout << endl; // va a capo per fare la prossima riga
    }

    return 0;
}