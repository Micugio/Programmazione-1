using namespace std;
#include <iostream>

long long fatt1 (int n, int m=1) { // calcola m*m+1*...*n
  if (n==0) return 1;
  if (m==n) return m;
  else return m*fatt1(n,m+1);
}

int main() {
  int n;

  cout << "n? ";
  cin >> n;

  cout << "fattoriale(" << n << ") = " << fatt1(n) << endl;

  return 0;
}