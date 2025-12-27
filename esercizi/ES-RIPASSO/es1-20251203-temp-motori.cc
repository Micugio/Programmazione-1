#include <iostream>
#include <fstream>

using namespace std;

// ESEGUIRE CON:   ./a.out temperatura1.txt temperatura2.txt

double Percentuale (double superato, double totale);

int main (int argc, char * argv[]) {
  fstream f1, f2;
  
  double t1 = 0.0;
  double t2 = 0.0;
  int superato = 0;
  int totale = 0;

  // RICORDA: argc = numero di elementi (parole) da input.
  if (argc!=3) {
    cerr << "Usa: ./a.out <fileinput1> <fileinput2>\n";
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
  // VERSIONE PROF: 
  // Funziona perchè nei file ci sono solo valori double, ogni valore è su una riga (cioè diviso da un separatore "a capo") e le righe sono uguali per i file.
  // QUINDI non serve fare controlli!
  while(f1 >> t1 && f2 >> t2) {  // Fino a quando leggo da uno o altro, basterebbe anche uno però così non leggerei in loop da entrambi i file.
    if (t1 > t2) {
      superato++;
    }
    totale++;
  }
*/

  // Prima faccio una lettera iniziale ALTRIMENTI non posso usare fail()
  f1 >> t1;
  f2 >> t2;
  while (!f1.fail()) {  // Scelgo di usare fail() perchè se non c'è un separatore dopo l'ultimo elemento letto NON posso USARE eof().
    if (t1 > t2) {
      superato++;
    }
    totale++;
    f1 >> t1; // continuo a leggere da entrambi i file in loop (NOTA: il puntatore ricorda la posizione in cui è arrivato ad ogni chiamata)
    f2 >> t2;
  }

  cout << "superato: " << superato << endl;
  cout << "totale: " << totale << endl;

  if (totale==0) {
    cout << "Il numero delle misurazioni è uguale a zero, per cui non posso calcolare la percentuale" << endl;
  }
  else {
    cout << "La percentuale di misurazioni in cui la temperatura del motore1 ha superato quella del motore2 è del " << Percentuale (superato, totale) << "%" << endl;
  }
  

  f1.close();
  f2.close();

  return 0;
}

double Percentuale (double superato, double totale) {
  double risultato;
  
  risultato = (superato/totale) * 100;

  return risultato;
}

/*
// VERSIONE PROF:
double Percentuale (int superato, int totale) {

  return ((double)superato/totale) * 100.0;;
}
*/