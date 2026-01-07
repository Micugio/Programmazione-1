using namespace std;
#include <iostream>

extern int csize;

extern int x;

extern void print_ciao();

int main() {
  print_ciao();
  x = csize;
  cout << "size = " << csize << ", x = " << x << endl;
}
