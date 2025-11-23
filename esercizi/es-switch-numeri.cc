#include <iostream>
using namespace std;

int main() {
    int numero;
    cout << "Inserisci numero: ";
    cin >> numero;

    switch (numero+2) {
        case 2: cout << "Buongiorno" << endl; break;
        case 3: cout << "Good Morning" << endl; break;
        default : cout << "Questa lingua non esiste!" << endl;
    }

    return 0;
}