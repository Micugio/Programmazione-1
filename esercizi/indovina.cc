#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int casuale;
    int prova;
    int num = 0;

    int x;

    srand(time(NULL));

    x = rand();
    cout << x << endl;

    casuale = rand()%((15-5)+1) + 5; //range intervallo 5-15
    cout << casuale;

    cout << "Indovina numero nell' intervallo 5-15";

    // Ciclo infinito con while (true)
    while (true) {
        num++;
        cin >> prova;
        if (casuale != prova) {
            cout << "Sbagliato, riprova: ";
        }
        else {
            break;
        }
    }
    
    cout << "Hai indovinato in " << num << " tentativi il numero " << casuale << endl;
    
    return 0;
}