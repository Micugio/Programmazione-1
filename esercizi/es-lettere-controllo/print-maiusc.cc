#include <iostream>
using namespace std;

bool controllaCarattere (char carattere);

char convertiCarattere(char carattere);

int main() {
    char carattereInput, carattereConvertito;
    bool minuscola;

    cout << "Inserisci lettera minuscola: ";
    cin >> carattereInput;
    
    minuscola = controllaCarattere(carattereInput);
    if (minuscola) { // Se maiuscola = true allora fa if altrimenti da else
        carattereConvertito = convertiCarattere(carattereInput);
        cout << carattereInput <<  " -> " << carattereConvertito << endl;
    }
    else {
        cout << "Errore" << endl;
    }

    return 0;
}

bool controllaCarattere (char carattere) {
    bool risultato;
    risultato = (carattere >= 'a' && carattere <= 'z');
    return risultato;
}

char convertiCarattere (char carattere)  {
    char risultato;
    risultato = carattere + ('A' - 'a');
    return risultato;
}