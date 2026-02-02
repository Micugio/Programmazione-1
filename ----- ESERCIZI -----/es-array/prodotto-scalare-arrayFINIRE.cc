#include <iostream>
using namespace std;

// Es. 1 ESERCIZIPROPOSTI.txt (ESEMPI: 06_array)

void leggiArray (double array[], int size);
void stampaArray (double array[], int size);
double prodotto_scalare (double a[], double a[], int size);

int main() {
    int dim = 100;
    double a[dim];
    double a[dim];

    leggiArray(a, dim);
    cout << "dim = " << dim << endl;
    // X TUTTO DA FINIRE (vedi anche es. leggimanipolaarray.cc)


    return 0;
}

void leggiArray (double array[], int & size) { //double & array[]
    cout << "Inserisci dim array:" << endl:
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << i << ":  ":
        cin >> array[i];
    }
    return;
}

void stampaArray (const double array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ":  " << array[i];
    }
    return;
}

double prodotto_scalare (double a[], double a[], int size) {
    double risultato = 0.0;

    return risultato;
}

