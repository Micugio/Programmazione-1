#include <iostream>
using namespace std;

int main() {

    int a=0;
    int b=0;
    int c=0;

    cout << "Inserisci il valore di a: " << endl;
    cin >> a;

    cout << "Inserisci il valore di b: " << endl;
    cin >> b;

    cout << "Inserisci il valore di c: " << endl;
    cin >> c;

    if (a<=b) {
        if (a<=c) {
            cout << a << endl;
        }
    }
    else if (b<=a) {
        if (b<=c) {
            cout << b << endl;
        }
    }
    else if (c<=a) {
        cout << "Iciao" << endl;
        if (c<=b) {
        cout << c << endl;
        }
    }
    return 0;
}