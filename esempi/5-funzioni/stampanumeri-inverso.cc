using namespace std;
#include <iostream>

void stampa (int n) { // m=0,m+1,m+2,...,m=n
  if (n<0)
    cout << endl;
  else {
    cout << n << " ";
    stampa(n-1);
  }
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;
  
  cout << "stampanumeri(" << n << ") = \n";
  stampa(n);

  return 0;
}
