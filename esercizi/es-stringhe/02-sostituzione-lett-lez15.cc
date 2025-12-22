using namespace std;
#include <iostream>
#include <fstream>

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

  while (myin.get(c)) { // Finche che lo stream "myin" legge un carattere dal file allora "myout" lo stampa nell'altro file (copia e incolla)
    if (c==oldlettera) {
      c = newlettera;
    }
    myout.put(c);
  }

  myin.close();
  myout.close();

  return 0;
}
