#include <iostream>
#include <fstream>

using namespace std;

// ESEGUIRE CON:   ./a.out temperatura1.txt temperatura2.txt

double Percentuale (int superato, int totale);

int main (int argc, char * argv[]) {
  fstream myin1, myin2;
  
  char ch;
  double temp1 = 0.0;
  double temp2 = 0.0;
  int superato = 0;

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=3) {
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
  
  myin1 >> temp1;
  myin2 >> temp2;
  cout << temp1 << endl;
  cout << temp2 << endl;
  cout << endl;
  if (temp1 > temp2) {
    ++superato;
  }

  while (!myin1.eof()) {
    myin1 >> temp1;
    myin2 >> temp2;
    cout << temp1 << endl;
    cout << temp2 << endl;
    cout << endl;
    if (temp1 > temp2) {
        ++superato;
    }
  }
  cout << superato << endl;

/*
  while(f1 >> v1 && f2 >> v2) {
      sumv1 += v1;
      sumv2 += v2;
      if (v1 > v2)
          pnum++;
      num++;
  }

  ///////////////////////////////////////
  
  f1 >> v1;
  f2 >> v2;
  while(!f1.eof()) {
    if (v1 > v2)
        pnum++;
    num++;
    f1 >> v1;
    f2 >> v2;
  }
  */

  myin1.close();
  myin2.close();

  return 0;
}

double Percentuale (int superato, int totale) {
    double risultato;

    risultato = (superato/totale) * 100;

    return risultato;
}