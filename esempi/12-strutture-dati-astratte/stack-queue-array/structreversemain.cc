using namespace std;
#include <iostream>
#include "structstack.h"

// COMPILARE CON: g++ structstack.cc structreversemain.cc

int main () 
{
  char res;
  int val,i,num;
  stack s;
 
  cout << "numero di elementi? ";
  cin >> num;
  init(s);
  for (i=0;i<num;i++) {
    cout << "Numero [" << i << "]? ";
    cin >> val;
    push(val,s);
  }

  // NOTA: questo for si può fare anche con un while o chiamata ricorsiva (in questo modo non serve sapere il numero di elementi che inserisco)
  for (i=0;i<num;i++) {
    top(val,s);
    pop(s);
    cout << val << endl;
  }
  deinit(s);
}


    
    
