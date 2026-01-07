using namespace std;
#include <iostream>
#include <fstream>

// CONSEGNA: leggere file di input (da riga di comando) e scrivere su file di output (da riga di comando) sostituendo ogni occorenza di un carattere scelto con un altro carattere scelto.

// ESEGUIRE CON:   ./a.out 02-input.txt 02-output.txt

int main (int argc, char * argv[]) {
  fstream myin, myout;
  
  char c, oldlettera, newlettera;

  cout << "Scegli la lettera da sostituire: " << endl;
  cin >> oldlettera;

  cout << "Scegli la lettera che sostituirà: " << endl;
  cin >> newlettera;




  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=3) {
    cerr << "Usa: ./a.out <fileinput> <fileoutput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin, non è mai stato aperto perché è andato in errore
  }

  myout.open(argv[2],ios::out);
  if (myout.fail()) {
     cerr << "Il file " << argv[2] << " non e' scrivibile\n";
     myin.close();
     exit(0);
  }

  while (myin.get(c)) { // Finchè che lo stream "myin" legge un carattere dal file ALLORA si esegue ciclo While
    if (c==oldlettera) {
      c = newlettera;
    }
    myout.put(c);
  }

  myin.close();
  myout.close();

  return 0;
}
