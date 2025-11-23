#include <iostream>
using namespace std;

void inizializza (int array[], int dim) {
    for (int i=  0; i < dim; i++) {
        array[i] = rand() % 10;
    }
    return;
}

void stampa (const int array[], int dim) {
    for (int i=0; i<dim; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

void selectionsort (int array[], int dim) {
    for (int i=0; i<dim; i++) { // ciclo per scorrere tutti gli elementi dell'array tranne l'ultimo (che per forza è il numero maggiore)
        int posMin = i;
        for (int j=i+1; j<dim; j++) { // ciclo che scorre solo gli elementi a destra di dove mi trovo
            if (array[j]<array[i]) { // per trovare se esiste un elemento più piccolo
                posMin = j;
            }
        }
    int scambio = array[j];
    array[j] = array[i];
    array[i] = scambio;
    }
}

int main() {
    int numero = 0;
    const int dim = 10;
    int array[dim];

    srand(time(NULL));

    inizializza (array, dim); 
    stampa (array, dim);
    selectionsort (array, dim);

    cout << "Array ordinato: ";
    cout << array[dim] << endl;

    
    return 0;
}