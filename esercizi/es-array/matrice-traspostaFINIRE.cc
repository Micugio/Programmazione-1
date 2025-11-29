#include <iostream>
using namespace std;

const int righe = 3;
const int colonne = 3;

void inizializza (int array[][colonne], int righe, int colonne) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++) {
            array[i][j] = rand() % 10;
        }
    }
    return;
}

void stampa (const int array[][colonne], int righe, int colonne) {
    for (int i=0; i<righe; i++){
        for (int j=0; j<colonne; j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int array[righe][colonne];
    
    srand(time(NULL));

    inizializza (array, righe, colonne);
    stampa (array, righe, colonne);
    
    return 0;
}