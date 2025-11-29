#include <iostream>
using namespace std;

void invertinum (int numero);

int main() {
    int numero;

    cout << "Inserisci un numero: ";
    cin >> numero;

    invertinum (numero);

    return 0;
}

void invertinum (int numero) {
    int risultato = 0;
    int cifra = 0;

    while (numero>0){
        cifra = numero % 10;
        numero = numero / 10;
        risultato *= 10; // Sposta la cifra a dx di un posto (decina) così posso sommare la cifra
        risultato += cifra;
    }

    cout << risultato << endl;
    return;
}