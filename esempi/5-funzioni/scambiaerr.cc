using namespace std;
#include <iostream>

void scambia(int ,int );

int a, b; // variabili globali


int main()
{
  do {
    cout << "dammi a e b (0 0 per terminare) ";
    cin >> a >> b ;
    cout << "a = " << a << " b= " << b << endl;
    scambia(a,b);
    cout << "a = " << a << " b= " << b << endl;
  } while ((a!=0)&&(b!=0));
		return 0;
}

void scambia(int n,int m)
{
  int t;
  t=n;
  n=m;
  m=t;
  // Senza variabile di appoggio t:
  // n = n + m;
  // m = n - m;
  // n = n - m;
  // Oppure:
  // n = n ^ m;
  // m = m ^ n;
  // n = n ^ m;
}
