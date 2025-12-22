#include <iostream>
using namespace std;

// Es. funziona ma non corretto, es. giusto è inverti-num.cc (nella cartella es-base)

void inverti (int & k);

int main() {
    int n = 0;

    do {
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<=0);

    inverti(n);

    return 0;
}

void inverti (int & k) {
    while (k!=0) {
        int sol = 0;
        sol = k % 10;
        cout << sol;
        k = k / 10;
    }
    cout << endl;
}
