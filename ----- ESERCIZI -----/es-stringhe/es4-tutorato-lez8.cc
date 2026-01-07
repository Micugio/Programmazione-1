using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

// CONSEGNA: leggere un file in input da riga di comando, file contiene numeri double divisa da virgola, fare la somma e la media dei numeri.

// ESEGUIRE CON:   ./a.out es4-file.txt

int main (int argc, char * argv[]) {
  fstream myin;
  
  double array[100];
  char str[100];
  char c;
  int n_str = 0;
  int n_array = 0;
  double somma = 0;
  double media = 0;


  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=2) {
    cerr << "Usa: ./a.out <fileinput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin, non è mai stato aperto perché è andato in errore
  }


  while (myin.get(c)) { // Finchè che lo stream "myin" legge un carattere dal file ALLORA si esegue ciclo While
    if (c != ',') { // Salva ogni carattere che legge != da ',' nella stringa str.
      str[n_str] = c;
      n_str++;
    }
    else {  
      str[n_str] = '\0'; // Aggiunge il terminatore di stringa per renderla valida.
      array[n_array] = atof(str); // Converte stringa str in double e salva numero in array.
      n_array++; // Aumenta indice array di uno, così ad ogni ciclo salvo in sequenza numeri.
      n_str = 0; // Resetta la stringa per il prossimo ciclo, il prossimo ciclo sovrascrivera la stringa.
    }
  }

  // IF per il caso in cui ultimo numero NON sia terminato da virgola.
  if (n_str != 0) { 
    str[n_str] = '\0';
    array[n_array] = atof(str);
    //n_array++; // Lo incremento perchè viene utilizzato anche come contatore per sapere quanti numeri ci sono nell'array.
  }

  for (int k = 0; k <= n_array; k++) {  // NOTA: se USO (n_array++) DEVO cambiare operatore condizione con (<).
    cout << array[k] << " ";
    somma += array[k];
  }
  cout << endl;
  cout << "Somma = " << somma << endl;

  media = somma / (n_array + 1);  // NOTA: n_array indica ultimo indice dell'array, QUINDI per sapere quanti numeri contiene array devo fare +1 (così conto anche l'indice 0 dell'array).
  cout << "Media = " << media << endl;

  myin.close();

  return 0;
}
