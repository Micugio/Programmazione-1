#include <iostream>
#include "cstack.h"

using namespace std;

typedef struct __stack__ __stack_s__;

struct _node_ {
  char data;
  struct _node_ * next;
};

struct __stack__ {
  _node_ * _s;
};

Stack StackInit(const unsigned dim) {
  __stack__ * s = new __stack__;
  s->_s = NULL;
  Stack st = {s};
  return st;
}

void StackDeinit(Stack & s) {
  _node_ * l = s._stack->_s;
  while(l != NULL) {
    _node_ * t = l;
    l = l->next;
    delete t;
  }
  delete s._stack;
}

bool StackIsFull(const Stack & s) {
  return false;
}

bool StackIsEmpty(const Stack & s) {
  return s._stack->_s == NULL;
}

bool Push(Stack & s, const char t) {
  if (StackIsFull(s)) return false;

  _node_ * n = new _node_;
  n->data = t;
  n->next = s._stack->_s;
  s._stack->_s = n;
  return true;
}

bool Pop(Stack & s) {
  if (StackIsEmpty(s)) return false;
  _node_ * t = s._stack->_s;
  s._stack->_s = s._stack->_s->next;
  delete t;
  return true;
}

bool Top(Stack & s, char & t) {
  if (StackIsEmpty(s)) return false;
  t = s._stack->_s->data;
  return true;
}

void Print(const Stack & s) {
  _node_ * l = s._stack->_s;
  while(l != NULL) {
    cout << l->data << " ";
    l = l->next;
  }
  cout << endl;
}
