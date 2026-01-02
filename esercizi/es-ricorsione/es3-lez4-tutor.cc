#include <iostream>
using namespace std;

int punteggio (int n, int ris) {
    if (n == 0) {
        return ris;
    }
    else {
        char c;
        cin >> c;
        
        if (c>='A' && c<='Z') {
            ris = ris + 10;
        }
        else if (c>='a' && c<='z') {
            ris = ris + 5;
        }
        else {
            ris = ris + 1;
        }
        
        return punteggio(n-1, ris);
    }
}

int main() {
    int n = 0;
    int ris = 0;
    int soluzione = 0;
    
    do {
        cout << "Inserisci un numero positivo: " << endl;
        cin >> n;
    } while (n<0);

    soluzione = punteggio(n, ris);
    cout << "Punteggio = " << soluzione << endl;

    return 0;
}
