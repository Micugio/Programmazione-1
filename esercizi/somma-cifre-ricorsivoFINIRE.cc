#include <iostream>
using namespace std;

int somma_cifre (int n) {
    int valore = n;

    if (n < 0) {
        n = -n;
    }
    if (n < 10) {
        return valore;
    }
    valore = n%10 + somma_cifre(n/10);
    return valore;
}

int main() {
    int n = 0;
    int valore = 0;

    cout << "Inserisci numero: ";
    cin >> n;
    
    somma_cifre(n);
    cout << valore << endl;

    return 0;
}