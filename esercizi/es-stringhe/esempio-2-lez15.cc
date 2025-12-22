using namespace std;
#include <iostream>
#include <fstream>

int main (int argc, char * argv[]) {
  fstream myin;
  
  char c;

  if (argc!=2) {
    cerr << "Usa: ./a.out <fileinput>\n";
    exit(0);
  }

  myin.open(argv[1],ios::in);

  if (myin.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin, non è mai stato aperto perché è andato in errore
  }

  while (myin.get(c)) { // Finche che lo stream "myin" legge un carattere dal file allora "myout" lo stampa nell'altro file (copia e incolla)
    cout.put(c);
  }
  cout << endl;

  myin.close();

  return 0;
}
