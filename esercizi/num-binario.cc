#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int binario, parziale, decimale, cifra, pos;
    
    cout << "Immetti un numero binario: ";
    cin >> binario;

    parziale = binario;
    decimale = 0;
    pos = 0;

    while (parziale>0) {
        cifra = parziale % 10;
        parziale /= 10;
        decimale += cifra*pow(2, pos++);
    }
    
    cout << "Ecco il numero decimale: " << decimale << endl;

    return 0;
}