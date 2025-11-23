#include <iostream>
using namespace std;

int potenza (int m, int n, int flag) {
    if (n == 0) {
        cout << "Risultato = 1" << endl;
        return 0;
    }
    if (n>0){
        return potenza (m, n-1, flag*m);
    }
    else {
        return flag;
    }
}

int main() {
    int m = 0;
    int n = 0;
    int flag = 1;

    cout << "Inserisci m = ";
    cin >> m;

    do {
        cout << "Inserisci numero positivo n = ";
        cin >> n;
    } while (n<0);
    
    /*
    for (int i = 0; i<n; i++) {
        flag = flag*m;
    }
    cout << "Risultato = " << flag << endl;
    */

    cout << "Risultato = " << potenza (m, n, flag) << endl;

    return 0;
}