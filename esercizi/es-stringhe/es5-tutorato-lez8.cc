using namespace std;
#include <iostream>
#include <fstream>
#include <cstdlib>

// ESEGUIRE CON:   ./a.out A.txt B.txt C.txt

int main (int argc, char * argv[]) {
  fstream myin1, myin2, myout;
  
  char c1, c2;
  char str1[100];
  char str2[100];

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=4) {
    cerr << "Usa: ./a.out <fileinput1> <fileinput2> <fileoutput>\n";
    exit(0);
  }

  myin1.open(argv[1],ios::in);

  if (myin1.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin1, non è mai stato aperto perché è andato in errore
  }

  myin2.open(argv[2],ios::in);

  if (myin2.fail()) {
    cerr << "Il file " << argv[2] << " non esiste\n";
    myin1.close();
    exit(0);
  }

  myout.open(argv[3],ios::out);

  if (myout.fail()) {
    cerr << "Il file " << argv[3] << " non è scrivibile\n";
    myin1.close();
    myin2.close();
    exit(0);
  }

/*
  // Funziona SOLO SE file di input hanno stessa lunghezza.
  while (myin1.get(c1) && myin2.get(c2)) { // Finche che lo stream "myin1" e "myin2" leggono un carattere dai file ALLORA si esegue ciclo While
    myout.put(c1);
    myout.put(c2);
  }
*/

/*
  // VERSIONE PERFETTA
  char c1, c2;

  while (true) {
    if (myin1.get(c1)) {
      myout.put(c1);
    }
    if (myin2.get(c2)) {
      myout.put(c2);
    }
    if (!myin1 && !myin2) { // entrambi i file sono finiti
      break;
    }
  }
*/

  int i = 0; // Serve per scorrere stringa str1.
  int j = 0; // Serve per scorrere stringa str2.

  // Crea stringa str1 e conta elementi della stringa
  while (myin1.get(c1)) {
    str1[i] = c1;
    i++;
  }
  str1[i]='\0';

  // Print stringa str1
  for (int h=0; h<i; h++) {
    cout << str1[h] << " ";
  }
  cout << endl;

  // Crea stringa str1 e conta elementi della stringa
  while (myin2.get(c2)) {
    str2[j] = c2;
    j++;
  }
  str2[j]='\0';

  // Print stringa str2
  for (int h=0; h<j; h++) {
    cout << str2[h] << " ";
  }
  cout << endl;



  int f = 0; // Serve per scorrere in modo alternato le due stringhe.

  // Nel caso in cui le due stringhe dei file di input NON abbiamo la stessa lunghezza
  while (f < i || f < j) {
    if (f < i) myout.put(str1[f]);
    if (f < j) myout.put(str2[f]);
    f++;
  }


  myin1.close();
  myin2.close();
  myout.close();

  return 0;
}
