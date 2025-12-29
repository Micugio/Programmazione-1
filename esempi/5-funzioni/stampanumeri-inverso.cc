using namespace std;
#include <iostream>

// VERSIONE PROF:
void stampa_inv1 (int n, int m=0) { // m=0,m+1,m+2,...,m=n
  if (m>n)
    cout << endl;
  else {
    stampa_inv1(n, m+1);
    cout << m << " ";
  }
}

/*
// LA MIA VERSIONE ispirata al PROF:
void stampa_inv1 (int n, int m=0) { // m=0,m+1,m+2,...,m=n
  if (m<=n) {
    stampa_inv1(n, m+1);
    cout << m << " ";
  }
}
*/

// LA MIA VERSIONE:
void stampa_inv2 (int n) { // m=0,m+1,m+2,...,m=n
  if (n<0)
    cout << endl;
  else {
    cout << n << " ";
    stampa_inv2(n-1);
  }
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;
  
  cout << "stampanumeri(" << n << ") = \n";
  stampa_inv1(n);

  return 0;
}
