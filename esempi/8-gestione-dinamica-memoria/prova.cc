using namespace std;
#include <iostream>

int main ()
{
  int * a;
  int n,i;
  cout << (long) &n << endl;
  do {
    cout << "quanti elementi? (0 per terminare): " ;
    cin >> n;
    a = new int[n];
				cout << "&a: " << (long)&a << endl;
				cout << "a: " << (long)a << endl;
    for (i=0;i<n;i++){
      cout << i+1 << ": ";
      cin >> a[i];
    }
    for (i=0;i<n;i++){
      cout << a[i] << " &a[" << i << "]: " << (long) &a[i] << endl ;
    }
    delete [] a;
  } while (n > 0);
  cout << endl << a[1] << endl; // pericolosa!
}
