#include <iostream>

#include<cstdlib>
#include<ctime>

using namespace std;

/*
NOTA per risolvere esercizio:
Mi salvo ogni valore alla volta in una variabile ("flag") e poi inverto ultimo valore con primo.
Non vedo invertire tutti i valori, devo fermarmi a metà, se indice è dispari (%2), se indice è pari (/2).
*/

void inizializza (int array[], int dim) {
    for (int i=0; i<dim; i++) {
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

void inverti (int array[], int dim) {
    int flag = 0;
    for (int dim; dim>(dim/2); dim--) {
        flag = dim;
        cout << array[dim] << " ";
    }
    return;
}




int main() {
    const int dim = 10;
    int array[dim];

    srand(time(NULL));

    inizializza (array, dim); 
    stampa (array, dim);
    inverti (array, dim);

    return 0;
}