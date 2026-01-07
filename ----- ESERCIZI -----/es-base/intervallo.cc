#include <iostream>
using namespace std;

int main() {

    int a=0;
    int b=0;
    int c=0;

    cout << "Inserisci il valore di a: " << endl;
    cin >> a;

    do {
        cout << "Inserisci il valore di b: " << endl;
        cin >> b;

        cout << "Inserisci il valore di c: " << endl;
        cin >> c;
    } while (b>c);
    
    if (a>=b && a<=c) {
        cout << -1 << endl;
    }
    if (a<b) {
        cout << 1 << endl;
    }
    if (a>c) {
       cout << 0 << endl;
    }
    
    return 0;
}