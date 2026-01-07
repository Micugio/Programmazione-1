using namespace std;
#include <iostream>
#include <cstring>

const int DIM = 80;

void stampa (const int array[], int dim) {
  for (int i = 0; i < dim; i++) {
      cout << array[i] << endl;
  }
  return;
}

int main () {
  char word[DIM];
  
  int a[26];

  cin.getline(word, DIM);

  for (int i=0; i<strlen(word); i++) {
    if (word[i]>='a' && word[i]<='z') {
      int dist = 0;
      dist = word[i]-'a';
      ++a[dist];
    }
  }

  stampa(a, 26);

  
  return 0;
}
