#include <iostream>
using namespace std;

// NOT (!) = valore opposto di quel valore (si usa una una sola variabile)
// AND (&&) = true se entrambi valori true (se c'è un false allora è false) 
// OR (||) = true se un valore è true
// XOR = true se sono valori diversi (true o false)
// valore booleano:    true = 1     false = 0

// ESERCIZIO 3 (Tutorato 29/09/2025):
int main() {

    double a, b, c, d, e;
    double media;

    cout << "valore 1...  ";
    cin >> a;

    cout << "valore 2...  ";
    cin >> b;

    cout << "valore 3...  ";
    cin >> c;

    cout << "valore 4...  ";
    cin >> d;

    cout << "valore 5...  ";
    cin >> e;

    media = (a+b+c+d+e)/5;
    cout << media << endl;

    return 0;
}