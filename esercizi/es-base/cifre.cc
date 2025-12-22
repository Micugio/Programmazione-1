#include <iostream>
using namespace std;

int main() {
    
    int n = 0;
    int i = 0;

    do {
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<=0);


    while (n!=0) {
        n = n / 10;
        ++i;
    }
    
    cout << "Numero di cifre: " << i << endl;

    return 0;
}