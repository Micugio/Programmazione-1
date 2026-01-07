#include <iostream>

#include<cstdlib>
#include<ctime>

using namespace std;

/*
CONSEGNA: 
Hai due array (array1 e array2), 
array2 è già inizializzata mentre array1 lo inizializzo io con numeri casuali (con una funzione)
e poi lo stampo (con una funzione).
Infine crea un'altra funzione che conta i numeri uguali alla stessa posizione.
*/

void inizializza (int array1[], int dim, int max) {
    for (int i=  0; i < dim; i++) {
        array1[i] = rand() % max;
    }
    return;
}

void stampa (const int array1[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    return;
}

void ugualianza (const int array1[], const int array2[], int dim) {
    int uguali = 0;
    for (int i = 0; i < dim; i++) {
        if (array1[i] == array2[i]) {
            uguali = uguali + 1;
        }
    }
    cout << "Conta i numeri uguali alla stessa posizione: " << uguali << endl;
    return;
}





int main() {
    const int dim = 10;
    int array1[dim];
    int array2[dim] = {0,1,2,3,4,5,6,7,8,9};
    int max = 0;

    cout << "Interisci numero massimo array: ";
    cin >> max;

    srand(time(NULL));

    inizializza (array1, dim, max); 
    stampa (array1, dim);
    ugualianza (array1, array2, dim);

    return 0;
}