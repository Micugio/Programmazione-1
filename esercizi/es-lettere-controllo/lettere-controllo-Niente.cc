#include <iostream>
using namespace std;

// Assumo che il valore delle minuscole precede le Maiuscole

int main() {
    int a=7, b=3;

    char lettera;

    cout << "Immetti un carattere: ";
    cin >> lettera;
    
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