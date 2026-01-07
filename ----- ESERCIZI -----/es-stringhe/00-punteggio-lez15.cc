using namespace std;
#include <iostream>

// CONSEGNA: leggere stringa in input da terminale e contare distanza assoluta tra coppie di caratteri.

int punteggio (char str[]) {
  int risultato = 0;

  if (str[0] >= 'A' && str[0] <= 'Z') {
    str[0] += 'a'-'A';
  }
  if (!(str[0] >= 'a' && str[0] <= 'z')) {
    return -1;
  }

  for (int k = 1; str[k] != '\0'; k++) {
    
    if (str[k] >= 'A' && str[k] <= 'Z') {
    str[k] += 'a'-'A';
    }
    if (str[k] >= 'a' && str[k] <= 'z') {
      if (str[k-1] >= str[k]) {
        risultato += str[k-1] - str[k];
      }
      else {
        risultato += str[k] - str[k-1];
      }
    }
    else {
      return -1;
    }
  }

  return risultato;
}


int main () {
  char str[31];

  do {
    cout << "Inserire una stringa ('/' per terminare): ";
    cin >> str;
    if (str[0] != '/') {
      cout << "Distanza assoluta tra i caratteri: " << punteggio(str) << endl;
      cout << endl;
    }
  } while (str[0] != '/');

  return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
// VERSIONE PROF:
/*
int punteggio(char str[]) {
    int sum = 0;

    // Controllo e conversione del primo carattere in minuscolo
    if (str[0] >= 'A' && str[0] <= 'Z') {
        str[0] = str[0] - 'A' + 'a';
    }
    
    // Se il primo carattere non è una lettera, ritorna errore
    if (str[0] < 'a' || str[0] > 'z') {
        return -1;
    }

    // Analisi a partire dal secondo carattere
    int k = 1;
    while (str[k] != '\0') {
        // Conversione in minuscolo se necessario
        if (str[k] >= 'A' && str[k] <= 'Z') {
            str[k] = str[k] - 'A' + 'a';
        }

        // Se è una lettera minuscola, calcola la differenza assoluta col precedente
        if (str[k] >= 'a' && str[k] <= 'z') {
            sum += abs(str[k] - str[k - 1]);
        } else {
            // Se non è una lettera valida, ritorna errore
            return -1;
        }
        k++;
    }

    return sum;
}


int main() {
    char choice;
    char text[32];

    do {
        cout << "Inserire una stringa: ";
        cin >> text;
        // Nota: cin >> si ferma al primo spazio. 
        // Per stringhe con spazi, si userebbe cin.getline(text, 32);

        int p = punteggio(text);

        if (p != -1) {
            cout << "Punteggio = " << p << endl;
        } else {
            cout << "Stringa non valida" << endl;
        }

        do {
            cout << "Vuoi continuare (s/n)? ";
            cin >> choice;
        } while (!(choice == 'n' || choice == 's')); 
        // Nota: Nel codice originale c'era un operatore XOR (^), 
        // ma la logica standard per ripetere finché l'input non è corretto è questa.

    } while (choice != 'n');

    return 0;
}
*/