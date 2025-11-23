#include <iostream>

#include<cstdlib>
#include<ctime>

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




int main() {
    const int dim = 10;
    int array[dim];

    srand(time(NULL));

    inizializza (array, dim); 
    stampa (array, dim);

    return 0;
}