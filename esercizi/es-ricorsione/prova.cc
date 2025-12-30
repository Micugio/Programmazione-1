#include <iostream>
using namespace std;

int somma (int n, int ris) {
    if (n<10) {
        cout << "DIO" << endl;
        ris += n % 10;
        return ris;
    }
    else {
        cout << "SPORCO" << endl;
        ris += somma(n/10, ris) % 10;
        return ris;
        //ris += ris;
    }
}

/*
int somma_ric (int n, int ris) {
    if (n<10) {
        cout << "DIO" << endl;
        ris += n % 10;
        return ris;
    }
    else {
        cout << "SPORCO" << endl;
        ris += somma_ric(n/10, ris) % 10;
        return ris;
        //ris += ris;
    }
}
*/

int main() {
    int n = 0;
    int ris = 0;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    /*
    ris = n % 10;
    cout << ris << endl;
    n = n / 10;
    ris = n % 10;
    cout << ris << endl;
    */

    cout << "Somma cifre = " << somma(n, ris) << endl;

    return 0;
}