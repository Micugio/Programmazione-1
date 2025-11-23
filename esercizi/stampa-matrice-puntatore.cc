#include <iostream>
using namespace std;

void inizializza (int array[], int dim) {
    for (int i=0; i<dim; i++) {
        array[i] = rand() % 10;
    }
    return;
}

void stampa (int *p, int dim) {
    for (int i=0; i<dim; i++) {
        cout << *(p+i) << " ";
    }
    cout << endl;
}

int main() {
    const int dim = 10;
    int array[dim];

    srand(time(NULL));

    inizializza (array, dim);
    stampa (array, dim);
    

    return 0;
}