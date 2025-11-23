#include <iostream>
using namespace std;

/*
QUANDO USARE "cerr" al posto di "cout":

Quando vuoi salvare l’output del programma su un file, 
se usi "cerr" salverai SOLO l’output prodotto da "cout" NON gli eventuali ERRORI (che appaiono SOLO sul terminale).
*/

int main() {
    int x;

    cout << "Inserisci un numero positivo: ";
    cin >> x;

    if (x < 0) {
        cerr << "Errore: il numero inserito non è positivo!" << endl;
        return 1; // termina il programma con codice di errore
    }

    cout << "Hai inserito: " << x << endl;
    return 0;
}
