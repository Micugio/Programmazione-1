#include <iostream>
using namespace std;

/*
Vedi soluzioni Laboratorio 06/11/2025 :
void inizializza_Puntatore ();
*/

const int righe = 3;
const int colonne = 4;

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

void stampaPuntMatrice (int *p, int righe, int colonne) {
    int flag = righe * colonne;
    for (int i=0; i<flag; i++){
        if (i%4==0){ // If per la formattazione dell'output (così stampa le righe a capo)
            cout << endl;
        }
        cout << *(p+i) << " ";
    }
    cout << endl;
    return;
}

int main() {
    int array[righe][colonne];

    srand(time(NULL));

    inizializza (array, righe, colonne);
    stampa (array, righe, colonne);
    stampaPuntMatrice (*array, righe, colonne);
    
    return 0;
}