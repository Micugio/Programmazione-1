#include <iostream>
using namespace std;

int divisione (int a, int b, int div) {
    a = a - b;
    div = div + 1;
    if (a >= b) {
        int divisione (int a, int b, int div)
        //a = a - b;
        //div = div + 1;
        return div;
    }
    else {
        return div, a;
    }
    
    return 0;
}

int main() {
    int a = 0;
    int b = 0;
    int div = 0;

    
    cout << "Dividendo a = "<< endl;
    cin >> a;
    cout << "Divisore b = "<< endl;
    cin >> b;

    divisione (a, b, div);

    cout << "Risultato: " << div << endl;
    cout << "Resto: " << a << endl;

    return 0;
}