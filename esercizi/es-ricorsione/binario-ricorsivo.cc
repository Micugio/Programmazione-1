#include <iostream>
using namespace std;

void binario (int n) {
    if (n<=0) {
        cout << "0";
        return;
    }
    else if (n==1) {
        cout << "1";
        return;
    }
    else {
        binario(n / 2);
        cout << n % 2;
        return;
    }
}

int main() {
    int n;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    cout << "Numero binario: " << endl;
    binario(n);
    cout << endl;

    return 0;
}