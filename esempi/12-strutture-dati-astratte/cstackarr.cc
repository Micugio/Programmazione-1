#include <iostream>
#include "cstack.h"

using namespace std;

typedef struct __stack__ __stack_s__;

struct __stack__ {
  int N;
  int dim;
  char * arr;
};

Stack StackInit(const unsigned dim) {
  __stack__ * s = new __stack__;
  s->N = 0;
  s->dim = dim;
  s->arr = new char[dim];
  Stack st = {s};
  return st;
}

void StackDeinit(Stack & s) {
  s._stack->N = 0;
  s._stack->dim = 0;
  delete[] s._stack->arr;
  delete s._stack;
}

bool StackIsFull(const Stack & s) {
  return s._stack->N == s._stack->dim;
}

bool StackIsEmpty(const Stack & s) {
  return s._stack->N == 0;
}

bool Push(Stack & s, const char t) {
  if (StackIsFull(s)) return false;

  s._stack->arr[s._stack->N] = t;
  s._stack->N++;
  return true;
}

bool Pop(Stack & s) {
  if (StackIsEmpty(s)) return false;
  s._stack->N--;
  return true;
}

bool Top(Stack & s, char & t) {
  if (StackIsEmpty(s)) return false;
  t = s._stack->arr[s._stack->N-1];
  return true;
}

void Print(const Stack & s) {
  for (int i = 0; i < s._stack->N; i++)
    cout << s._stack->arr[i] << " ";
  cout << endl;
}
