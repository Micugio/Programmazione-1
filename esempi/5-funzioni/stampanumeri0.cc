using namespace std;
#include <iostream>

void stampa1 (int n, int m=0) { // m=0,m+1,m+2,...,m=n
  if (m>n)
    return;  // OPPURE: cout << endl;
  else {
    cout << m << " ";
    stampa1(n, m+1);
  }
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;
  
  cout << "stampanumeri(" << n << ") = \n";
  stampa1(n);

  return 0;
}
