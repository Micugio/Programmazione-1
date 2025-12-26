#include <iostream>
#include <fstream>

using namespace std;

// ESEGUIRE CON:   ./a.out temperatura1.txt temperatura2.txt

double Percentuale (int superato, int totale);

int main (int argc, char * argv[]) {
  fstream f1, f2;
  
  char ch;
  double t1 = 0.0;
  double t2 = 0.0;
  int superato = 0;

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=3) {
    cerr << "Usa: ./a.out <fileinput1> <fileinput2> <fileoutput>\n";
    exit(0);
  }

  f1.open(argv[1],ios::in);

  if (f1.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0); // NOTA: Non serve chiudere lo stream myin1, non è mai stato aperto perché è andato in errore
  }

  f2.open(argv[2],ios::in);

  if (f2.fail()) {
    cerr << "Il file " << argv[2] << " non esiste\n";
    f1.close();
    exit(0);
  }
  
  /*
  ALTRA VERSIONE MIGLIORE (funziona perchè so che ci sono solo valori double e ogni valore è su una riga senza spazi, QUINDI non serve fare controlli)
  while(f1 >> v1 && f2 >> v2) {  // Fino a quando leggo da uno o altro, basterebbe anche uno però non farei comando....FINIRE
      sumv1 += v1;
      sumv2 += v2;
      if (v1 > v2)
          pnum++;
      num++;
  }
*/

  // Prima faccio una lettera iniziale ALTRIMENTI non posso usare eof()
  f1 >> t1;
  f2 >> t2;
  while (!f1.eof()) {  // Basta controllare se il file è terminato (non serve fail() perchè ci sono solo double)
    if (t1 > t2) {
      ++superato;
    }
    f1 >> t1; // continuo a leggere da entrambi i file (NOTA: il puntatore ricorda la posizione in cui è arrivato ad ogni chiamata)
    f2 >> t2;
  }

  f1.close();
  f2.close();

  return 0;
}

double Percentuale (int superato, int totale) {
    double risultato;

    risultato = (superato/totale) * 100;

    return risultato;
}