using namespace std;
#include <iostream>

int main ()
{
  int n,i;
  long long fact;
  cout << "dammi il numero >= 0: ";
  cin >> n;
  if (n >=0) {
    i = 1;
    fact = 1;

    while (i<=n) {
      fact *= i;
      i++;
    }
    cout  << "Fact = "  << fact   << endl;
  }
  else {
    cout << "Inserito un numero negativo" << endl;
  }
  return 0;
}
