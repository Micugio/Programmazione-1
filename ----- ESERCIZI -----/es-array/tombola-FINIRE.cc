#include <iostream>
using namespace std;

const int righe = 3;
const int colonne = 9;


void inizializzaTabella (int tabella[][colonne], int righe, int colonne) {
    for (int i=0; i<righe; i++) {
            for (int j=0; j<colonne; j++){
                int numero = rand()%2;
                cout << numero << endl;
                if (numero!=0) {
                    tabella[i][j] = (rand()%10) + (10*j);
                }
                else {
                    tabella[i][j] = -1;
                }
                
        }
            
    }
        
    return;
}

/*
void inizializzaTabella (int tabella[][colonne], int righe, int colonne) {
    int numero = 0;
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++){
            do {
                numero = rand();
            } while (numero>(10*j) && numero<(10*(j+1)));
            tabella[i][j] = numero;
        }
    }
        
    return;
}
*/

void stampaTabella (const int tabella[][colonne], int righe, int colonne) {
    for (int i=0; i<righe; i++) {
        for (int j=0; j<colonne; j++){
            cout << tabella[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

/*
void controllo (){
    int verifica = 0;
    verifica = tabella
}
*/

int main() {
    int tabella[righe][colonne];
    
    srand(time(NULL));

    inizializzaTabella (tabella, righe, colonne); 
    stampaTabella (tabella, righe, colonne);
    

    return 0;
}