using namespace std;
#include <iostream>

int  num;
long long fattoriale;

//calcolo del fattoriale
long long fact(int x)
{
  std::cout << fattoriale << std::endl;
  {
  long long fattoriale = 1;
  for (int i=1; i<=x; i++)
    fattoriale *= i;
  return fattoriale;

  }
}

int main()
{
  cout << "Dammi il numero: ";
  cin >> num;
  fattoriale=fact(num);
  cout  << "Fact = "  << fattoriale   << " " << fact(num) << endl;
  return 0;
}
