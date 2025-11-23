#include <iostream>
using namespace std;

// NOT (!) = valore opposto di quel valore (si usa una una sola variabile)
// AND (&&) = stesso valore restituisce quel valore 
// OR (||) = true se un valore è true
// XOR = true se sono valori diversi (true o false)
// valore booleano:    true = 1     false = 0

// ESERCIZIO 1 (Tutorato 29/09/2025):
int main() {
    
    bool A = 1;
    bool B = 1;
    bool flag;

    flag = (A || B) && (!B ^ A);

    cout << flag << endl;
    
    return 0;
}