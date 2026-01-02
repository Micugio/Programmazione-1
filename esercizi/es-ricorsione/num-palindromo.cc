#include <iostream>
using namespace std;

// NOTA: questa funzione ricorsiva è tail recursive (può avere return con accumulatore), cioè costruisce il numero inverso durante l'andata della chiamata ricorsiva, 
//       in pratica il return con la chiamata ricorsiva esegue il loop la ricorsione fino a quando non si arriva al caso base.

int inverti_ric (int n, int val) {
    if (n <= 0) {
        return val;
    }
    else {
        val = (val * 10) + (n % 10);
        return inverti_ric(n/10, val); // Tail Recursive da questa riga, non ci sono altri calcoli (al ritorno) dopo la chiamata.
    }
}

int main() {
    int n = 0;
    int val = 0;
    int palindromo = 0;
    
    do { // Ti fa inserire in continuazione un numero finchè quest'ultimo è un numero intero positivo.
        cout << "Inserisci un numero intero positivo: ";
        cin >> n;
    } while (n<0);

    palindromo = inverti_ric(n, val);
    cout << n << endl;
    cout << palindromo << endl;


    if (n == palindromo) {
        cout << "Il numero " << n << " É palindromo!" << endl;
    }
    else {
        cout << "Il numero " << n << " NON è palindromo!" << endl;
    }

    return 0;
}
