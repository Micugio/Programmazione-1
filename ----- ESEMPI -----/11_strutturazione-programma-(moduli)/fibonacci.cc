using namespace std;
#include <iostream>

int depth = 0; // globale

void printspaces(int n)
{
  for (int i=0;i<n;i++)
    cout << "   ";
}

long long f (int n)
{
  long long res;
  cout << "Indirizzo di depth prima: " << (long)&depth << endl;

  static int depth = 0; // memorizzata in area statica
  cout << "Indirizzo di depth: " << (long)&depth << endl;
  depth++;
  printspaces(depth);
  cout << "> f(" << n << ")\n";

  if (n==0||n==1)
    res = 1;
  else
    res = f(n-1)+f(n-2);

  printspaces(depth);
  cout << "< " <<  res << endl;
  depth--;

  return res;
}

int main()
{
  int n;
  cout << "n? ";
  cin >> n;
  cout << "Indirizzo di depth: " << (long)&depth << endl;

  cout << "f(" << n << ") = " << f(n) << endl;
  cout << depth << endl; // Non utilizzabile
  return 0;
}
