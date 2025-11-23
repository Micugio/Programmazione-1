#include <iostream>
using namespace std;

bool controllaCarattere (char carattere);

void convertiCarattere(char carattere);

int main() {
    char carattereInput, carattereConvertito;
    bool minuscola;

    cout << "Inserisci lettera minuscola: ";
    cin >> carattereInput;
    
    minuscola = controllaCarattere(carattereInput);
    if (minuscola) { // Se maiuscola = true(1) allora fa if altrimenti da else
        carattereConvertito = carattereInput;
        convertiCarattere(carattereConvertito);
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

void convertiCarattere (char &carattere)  {
    char risultato;
    risultato = carattere + ('A' - 'a');
    carattere = risultato;
    return; // No return perchè è una funzione void
}