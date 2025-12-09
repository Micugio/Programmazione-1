using namespace std;
#include <iostream>

struct S {
  int value;
  S next; // SBAGLIATO perchè non uso un puntatore, compilatore non sa quale spazio di memoria assegnarli.
};

int main ()
{

  S x;

  return 0;
}
