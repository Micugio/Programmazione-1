using namespace std;
#include <iostream>

int somma(int n) {
  if (n == 0)
    return 0; // caso base
  else
    return n + somma(n-1); // passo ricorsivo // NOTA: (n + somma(n-1)) == (somma(n-1) + n)
}


int main() {
  int n;

  cout << "n? ";
  cin >> n;

  cout << "Somma dei numeri fino a " << n << " = " << endl;
  cout << somma(n) << endl;

  return 0;
}
