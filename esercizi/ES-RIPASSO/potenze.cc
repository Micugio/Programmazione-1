#include <iostream>
using namespace std;

int main() {
    
    int a = 0;
    int n = 0;
    int sol = 0;

    cout << "Inserisci a: ";
    cin >> a;

    cout << "Inserisci n: ";
    cin >> n;

    while (!(n>=1)) {  // OPPURE (n<=1)
        cout << "ERRORE!" << endl;
        cout << "Inserisci n: ";
        cin >> n;
    }

    cout << "Output a: ";
    for (int i=0; i<n; i++) {

    
        if (i==0) {
            sol = a;
            cout << sol << " ";
        }
        else if (i==1){
            sol = sol * a;
            cout << sol << " ";
        }
        else {
            sol = sol * a;
            cout << sol << " ";
            sol = 0;
        }  
    }
    cout << endl;

    return 0;
}