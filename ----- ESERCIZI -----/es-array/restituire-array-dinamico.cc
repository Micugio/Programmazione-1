#include <iostream>
using namespace std;

// Funzione che restituisce un array dinamico di bool
bool* creaArrayBool(int size) {
    bool* array = new bool[size];  // Allocazione dinamica della memoria

    // Inizializziamo l'array con valori fittizi
    for (int i = 0; i < size; ++i) {
        array[i] = (i % 2 == 0);  // Imposta ogni elemento alternato come true/false
    }

    return array;
}

int main() {
    int size = 5;
    bool* arr = creaArrayBool(size);
    
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Ricordati di deallocare la memoria!
    delete[] arr;

    return 0;
}