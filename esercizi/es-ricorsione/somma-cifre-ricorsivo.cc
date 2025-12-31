#include <iostream>
using namespace std;

int somma (int n) {
    if (n < 10) {
        return n;
    }
    else {
        return somma(n/10) + n % 10;
    }
}

int main() {
    int n = 0;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    cout << "Somma cifre = " << somma(n) << endl;

    return 0;
}





/*
// VERSIONE con variabile di appoggio per return  (NON USARE QUESTA VERSIONE!!!)
// NOTA: val NON è una variabile per accumulare il risultato ad ogni passo ricorsivo, è solo un supporto per il return in modo da scrivere il codice più ordinato.
int somma (int n) {
    int val = 0;
    if (n < 10) {
        val = n;
        return val;
    }
    else {
        val = somma(n/10) + n % 10;
        return val;
    }
}
*/