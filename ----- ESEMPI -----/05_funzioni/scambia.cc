using namespace std;
#include <iostream>

int a, b; // GLOBALI PER ESSERE TRACCIATE DAL DEBUGGER

void scambia(int &, int &);

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

void scambia(int & n,int & m)
{
  int t;
  t=n;
  n=m;
  m=t;
}
