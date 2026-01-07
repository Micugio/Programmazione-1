#include <iostream>
#include <cstdlib>
using namespace std;

struct Prodotto {
 char nome[50];
 float prezzo[7];
};

float k = 9.2f;

void stampa_prodotto (char nome[50], float prezzo[7]) {
    cout << nome << endl;
    for (int i=0; i<7; i++) {
        cout << "prezzo" << "[" << i << "]" << " = " << prezzo[i] << endl;
    }
    cout << endl;
    return;
}

float prezzo_medio (float prezzo[7]) {
    float media;
    for (int i=0; i<7; i++) {
        media += prezzo[i];
    }
    media = media / 7;
    return media;
}

// NOTA: la funzione sconta gli array dei prezzi già esistenti (cioè MODIFICA gli ARRAY delle strutture).
void sconto (float prezzo[7], int val_sconto) {
    for (int i=0; i<7; i++) {
        // ESEMPIO (voglio fare prezzo - 30%):
        // 100 - 30 = 70  ->  70 / 100.0 = 0.7  ->  prezzo * 0.7 = RISULTATO
        prezzo[i] = prezzo[i]*((100-val_sconto)/100.0);
        cout << "prezzo" << "[" << i << "]" << " = " << prezzo[i] << endl;
    }
    return;
}
/*
// NOTA: la funzione sconto crea un nuovo array e applica lo sconto (cioè NON MODIFICA gli ARRAY delle strutture).
void sconto (float prezzo[7], int val_sconto) {
    for (int i=0; i<7; i++) {
        float sconto; // QUA creo un nuova variabile senza modifica l'array passato alla funzione.
        // ESEMPIO (voglio fare prezzo - 30%):
        // 100 - 30 = 70  ->  70 / 100.0 = 0.7  ->  prezzo * 0.7 = RISULTATO
        sconto = prezzo[i]*((100-val_sconto)/100.0); 
        cout << "prezzo" << "[" << i << "]" << " = " << sconto << endl;
    }
    return;
}
*/

// (true se il primo prodotto minore del secondo prodotto in quel i-esimo giorno, altrimenti false)
bool * compare (float a[], float b[]) {
    bool * array = new bool[7];
    for (int i=0; i<7; i++) {
        if (a[i] < b[i]) {
            array[i] = true;
        }
        else {
            array[i] = false;
        }
    }

    return array;
}


int main() {
    Prodotto a, b;

    srand(time(NULL));

    // INSERISCI PREZZI Prodotto a
    cout << "Nome prodotto a: " << endl;
    cin >> a.nome;
    for (int i = 0; i < 7; i++) {
        float val = 0;
        val = (rand() % 100) / 100.0;
        a.prezzo[i] = val;
    }
    /*
    // INSERISCI TU:
    for (int i=0; i<7; i++) {
        float val = 0;
        cout << "Inserisci prezzo con la virgola: " << endl;
        cin >> val;
        a.prezzo[i]= val;
    }
    */

    cout << endl;

    // INSERISCI PREZZI Prodotto b
    cout << "Nome prodotto b: " << endl;
    cin >> b.nome;
    for (int i = 0; i < 7; i++) {
        float val = 0;
        val = (rand() % 100) / 100.0;
        b.prezzo[i] = val;
    }
    /*
    // INSERISCI TU:
    for (int i=0; i<7; i++) {
        float val;
        cout << "Inserisci prezzo con la virgola: " << endl;
        cin >> val;
        b.prezzo[i]= val;
    }
    */

    cout << endl;

    // STAMPA STRUTTURE
    stampa_prodotto(a.nome, a.prezzo);
    cout << endl;
    stampa_prodotto(b.nome, b.prezzo);

    // PREZZO MEDIO
    cout << "Prezzo medio Prodotto a: " << prezzo_medio(a.prezzo) << endl;
    cout << endl;
    cout << "Prezzo medio Prodotto b: " << prezzo_medio(b.prezzo) << endl;

    // SCONTO
    int val_sconto = 0;
    cout << "Inserisci sconto: " << endl;
    cin >> val_sconto;

    cout << endl;

    cout << "Ecco gli sconti su ogni prezzo del Prodotto a: " << endl;
    sconto(a.prezzo, val_sconto);
    cout << endl;
    cout << "Ecco gli sconti su ogni prezzo del Prodotto b: " << endl;
    sconto(b.prezzo, val_sconto);

    cout << endl;

    // STAMPA STRUTTURE
    stampa_prodotto(a.nome, a.prezzo);
    cout << endl;
    stampa_prodotto(b.nome, b.prezzo);


    // CONFRONTO PREZZI
    bool * arr = compare(a.prezzo, b.prezzo);

    cout << "Quando il Prodotto a è meno costoso del Prodotto b: " << endl;
    for (int i=0; i<7; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Ricordati di deallocare la memoria!

    return 0;
}