#include <iostream>

using namespace std;

#include "cstack.h"
// Conversione di una espressione da infissa a postfissa
// e.g. infissa  : ((1 + 10) * (20 + 30)) + 40
//      postfissa: 1 10 + 20 30 + * 40 +
void inf2post(const char * e) {
  Stack s = StackInit();
  char c;

  for(int i = 0; e[i] != '\0'; i++) {
    if ((e[i] == '(') || (e[i] == ' ')) continue;
    if (e[i] == ')') {
      if (Top(s, c)) {
        Pop(s);
        cout << c << " ";
      }
    }
    if ((e[i] == '+') || (e[i] == '-') ||
        (e[i] == '*') || (e[i] == '/')) {
      if (!Push(s, e[i])) cout << "ERRORE";
    }
    if ((e[i] >= '0') && (e[i] <= '9'))
      cout << e[i];
    if (((e[i] >= '0') && (e[i] <= '9')) &&
        !((e[i+1] >= '0') && (e[i+1] <= '9')))
      cout << " ";
  }
  // The top level parenthesis are missing
  if (Top(s, c)) {
    cout << c;
  }
  cout << endl;
  StackDeinit(s);
}

// Rimuove un elemento da uno stack mantenendo ordine di quello che
// era esistente prima.
//
// Esempio di Applicazione pratica:
// Ho un treno composto da vagoni a b c d e f, ho un binario di
// supporto e voglio rimuovere vagone d mantenendo ordine.
bool uncouple(Stack & s, char c) {
  Stack s1 = StackInit();
  bool result = false;

  while ((! StackIsEmpty(s)) && (result == false)) {
    char r;
    Top(s, r); Pop(s);
    if (r == c) {
      result = true;
      break;
    }
    else
      Push(s1, r);
  }
  while(! StackIsEmpty(s1)) {
    char r;
    Top(s1, r);
    Pop(s1);
    Push(s, r);
  }

  StackDeinit(s1);
  return result;
}

// IDEA: Svuoto lo stack ricorsivamente con Pop (inoltre ad prima di ogni Pop faccio una Top per salvarmi il valore in una variabile temp (char r)) 
//       e lo ricostruisco mentre risalgo con Push controllando ogni volta se il char salvato (r) è uguale al char che cerco (c), se è uguale non faccio la Push.
void uncouple_ric(Stack & s, char c) {
    if (StackIsEmpty(s)) return;
    char r;
    Top(s, r); 
    Pop(s);
    uncouple_ric(s, c);
    if (r != c) Push(s, r);
}
/*
COMPORTAMENTO:
La ricorsione viene sempre chiamata.
La decisione (r != c) viene fatta in risalita.
Lo stack viene:
- completamente svuotato.
- ricostruito senza gli elementi uguali a c.
*/


void test_uncouple() {
  Stack s1 = StackInit();

  Push(s1, 'a');
  Push(s1, 'b');
  Push(s1, 'c');
  Push(s1, 'd');
  Push(s1, 'e');
  Push(s1, 'f');

  Print(s1);
  uncouple(s1, 'd');
  Print(s1);
  uncouple_ric(s1, 'c');
  Print(s1);
  StackDeinit(s1);
}

int main() {
  char p[] = "((1 + 10) * (20 + 30)) + 40";

  cout << p << endl;
  inf2post(p);

  cout << "-------------------------" << endl;
  test_uncouple();
}
