#include <iostream>
using namespace std;

int main() {
    char lettera;
    cout << "Inserisci la lingua: ";
    cin >> lettera;

    switch (lettera) { // NOTA: la condizione può essere anche una espressione matematica con numeri
        case 'i': cout << "Buongiorno" << endl; break;
        case 'e': cout << "Good Morning" << endl; break;
        default : cout << "Questa lingua non esiste!" << endl;
    }

    return 0;
}