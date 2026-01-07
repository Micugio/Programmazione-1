using namespace std;
#include <iostream>

// DICHIARAZIONE OBBLIGATORIA in questo caso, perchè in funzione pari chiamo funzione dispari che non sarebbe ancora definita senza dichiarazione.
bool pari(int n);
bool dispari(int n);

int main() {
  int n;
  cout << "n? ";
  cin >> n;
  if (n>=0)
    cout << n << " è " << (pari(n) ? "pari" : "dispari") << endl;
  else
    cout << n << " è minore di zero" << endl;
  return 0;
}

bool pari(int n) {
  bool ris;
  if (n==0)
    ris = true;
  else
    ris = dispari(n-1);
  return ris;
}

bool dispari(int n) {
  bool ris;
  if (n==0)
    ris = false;
  else
    ris = pari(n-1);
  return ris;
}
