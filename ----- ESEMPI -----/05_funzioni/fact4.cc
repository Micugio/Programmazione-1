#include "fact4.h"

long long fact(int n) {
  long long fatt = 1;
  for (int i=1; i<=n; i++)
    fatt *= i;
  return fatt;
}
