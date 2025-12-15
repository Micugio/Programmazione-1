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
        cout << prezzo[i] << " / ";
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

void sconto (float prezzo[7], int val_sconto) {
    for (int i=0; i<7; i++) {
        float sconto;
        // ESEMPIO (voglio fare prezzo - 30%):
        // 100 - 30 = 70  ->  70 / 100.0 = 0.7  ->  prezzo * 0.7 = RISULTATO
        sconto = prezzo[i]*((100-val_sconto)/100.0);
        cout << "prezzo" << "[" << i << "]" << " = " << sconto << endl;
    }
    return;
}

bool *compare () {
    bool arrBool [7];

    return arrBool;
}

bool compare ()




int main() {
    Prodotto a, b;

    srand(time(NULL));

    cout << "Nome prodotto a: " << endl;
    cin >> a.nome;
    for (int i = 0; i < 7; i++) {
        float val = 0;
        val = (rand() % 100) / 100.0;
        a.prezzo[i] = val;
    }
    /*
    // INSERISCI TU PREZZI:
    for (int i=0; i<7; i++) {
        float val = 0;
        cout << "Inserisci prezzo con la virgola: " << endl;
        cin >> val;
        a.prezzo[i]= val;
    }
    */

    cout << endl;

    cout << "Nome prodotto b: " << endl;
    cin >> b.nome;
    for (int i = 0; i < 7; i++) {
        float val = 0;
        val = (rand() % 100) / 100.0;
        b.prezzo[i] = val;
    }
    /*
    // INSERISCI TU PREZZI:
    for (int i=0; i<7; i++) {
        float val;
        cout << "Inserisci prezzo con la virgola: " << endl;
        cin >> val;
        b.prezzo[i]= val;
    }
    */

    cout << endl;

    stampa_prodotto(a.nome, a.prezzo);
    cout << endl;
    stampa_prodotto(b.nome, b.prezzo);

    cout << "Prezzo medio Prodotto a: " << prezzo_medio(a.prezzo) << endl;
    cout << endl;
    cout << "Prezzo medio Prodotto b: " << prezzo_medio(b.prezzo) << endl;

    int val_sconto = 0;
    cout << "Inserisci sconto: " << endl;
    cin >> val_sconto;

    cout << "Ecco gli sconti su ogni prezzo del Prodotto a: " << endl;
    sconto(a.prezzo, val_sconto);
    cout << endl;
    cout << "Ecco gli sconti su ogni prezzo del Prodotto b: " << endl;
    sconto(b.prezzo, val_sconto);

    bool array[7];



    return 0;
}