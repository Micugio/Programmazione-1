#include <iostream>
using namespace std;

/* RICORDA
valore booleano: true=1 false=0

(a sempre minore b, A sempre minore a) 
Assumo che il valore delle Maiuscole precede le minuscole
E carattere in input è una lettera
*/

int main() {
    cout << "Immetti un carattere: ";
    cin >> din;

    // Dichiarazione
    char lettera;

    
    
    if (lettera>='a' && lettera<='z')  {
        lettera -= 'a'-'A';
        cout << "È una lettera minuscola " << endl;
        cout << "Ecco la lettera Maiuscola... ";
        cout << lettera << endl;
    }
    else {
        lettera += 'a'-'A';
        cout << "È una lettera Maiuscola" << endl;
        cout << "Ecco la lettera minuscola... ";
        cout << lettera << endl;
    }

    return 0;
}