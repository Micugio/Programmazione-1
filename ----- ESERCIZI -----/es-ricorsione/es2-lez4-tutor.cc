#include <iostream>
using namespace std;


// CONSEGNA: Stampa in sequenza numeri da 0 a n, prima numeri pari in ordine crescente, poi numeri dispari in ordine decrescente.


// NOTA: Con la chiamata ricorsiva la parte sopra viene eseguita in loop (all'andata) fino a quando caso base è vero.
//       QUANDO il caso base è vero a quel punto si esegue (al ritorno) la parte sotto un numero di volte uguale alla parte sopra, DOPO QUESTO finisce funzione.

void stampa (int n, int i=0) {  // Scrivo (int i=0) così non serve dichiarare (i) all'interno del main modificandolo.
    if (i > n) {
        return;
    }
    else {
        if (i%2 == 0) {  // Stampa numeri pari all'andata (i va da 0 a n)
            cout << i << " ";
        }

        stampa(n, i+1); // Chiamata ricorsiva

        if (i%2 != 0) {  // Stampa numeri dispari al ritorno (i va da n a 0)
            cout << i << " ";
        }
    }
}

int main() {
    int n = 0;
    
    do {
        cout << "Inserisci un numero positivo: " << endl;
        cin >> n;
    } while (n<0);

    stampa(n);
    cout << endl;

    return 0;
}
