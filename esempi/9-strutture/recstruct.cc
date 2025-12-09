using namespace std;
#include <iostream>

struct S {
  int value;
  S *next; // GIUSTO, uso un puntatore che occupa sempre lo stesso spazio di memoria.
};

int main ()
{

  S x = {4 , NULL};

  return 0;
}
