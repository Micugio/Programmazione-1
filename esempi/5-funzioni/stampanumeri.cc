using namespace std;
#include <iostream>

void stampa1 (int n, int m=0) { // m,m+1,...,n-1,n
  if (m>n)
    cout << endl;
  else {
    cout << m << " ";
    stampa1(n, m+1);
  }
}

void stampa (int n) {
  stampa1 (0,n);
}

int main()
{
  int n;
  cout << "n? ";
  cin >> n;
  cout << "stampanumeri(" << n << ") = \n";
  stampa1(n);
return 0;
}
