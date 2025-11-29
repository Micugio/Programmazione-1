#include <iostream>
using namespace std;

void inizializza (int array[], int dim) {
    for (int i=  0; i < dim; i++) {
        array[i] = rand() % 10;
    }
    return;
}

void stampa (const int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

/*
// MIO METODO (non funziona)
int ricercaSequenziale (const int array[], int dim, int numero) {
    int risultato = 0;
    for (int i=0; i<dim; i++) {
        if (array[i]==numero) {
            risultato = i;
            return risultato;
        }
        else {
            risultato = -1;
            return risultato;
        }
    }
    return 0;
}
*/

int ricercaSequenziale (const int array[], int dim, int numero) {
    int risultato = -1;
    for (int i=0; i<dim; i++) {
        if (array[i]==numero) {
            risultato = i;
            dim = i;
        }
    }
    return risultato;
}

int main() {
    int numero = 0;
    const int dim = 10;
    int array[dim];

    cout << "Inserisci numero da cercare: " << endl;
    cin >> numero;

    srand(time(NULL));

    inizializza (array, dim); 
    stampa (array, dim);

    cout << "Il numero si trova in posizione: ";
    cout << ricercaSequenziale (array, dim, numero) << endl; // NOTA: se il numero non c'è nell'array restituisce -1.

    
    return 0;
}