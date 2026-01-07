using namespace std;
#include <iostream>
#include <cstring>

const int DIM = 80;

int main () {
  char word[DIM];
  char c;
  int vocali=0;
  int consonanti=0;
  

  cin.getline(word, DIM);
  
  for (int i=0; i<strlen(word); i++) {
    if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u') {
      vocali=vocali+1;
    }
    else if (word[i]>='b' && word[i]<='z'){
      consonanti=consonanti+1;
    }
  }

  cout << "vocali: " << vocali << endl;
  cout << "consonanti: " << consonanti << endl;

  
  return 0;
}
