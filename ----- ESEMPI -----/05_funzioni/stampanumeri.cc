using namespace std;
#include <iostream>

void stampa1 (int n, int m) { // m=0,m+1,m+2,...,m=n
  if (m>n)
    cout << endl;
  else {
    cout << m << " ";
    stampa1(n, m+1);
  }
}

void stampa (int n) {
  stampa1 (n,0);
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;
  
  cout << "stampanumeri(" << n << ") = \n";
  stampa(n);

  return 0;
}
