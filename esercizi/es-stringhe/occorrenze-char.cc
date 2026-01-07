#include <iostream>
using namespace std;

const int DIM = 80;

void stampa (const int array[], int dim) {
  for (int i = 0; i < dim; i++) {
    cout << char('a' + i) << " : " << array[i] << endl;
  }
}

int main () {
  char word[DIM];
  int a[26] = {0};   // inizializzazione fondamentale

  cin.getline(word, DIM);

  for (int i = 0; word[i] != '\0'; i++) {

    // lettera minuscola
    if (word[i] >= 'a' && word[i] <= 'z') {
      int dist = word[i] - 'a';
      ++a[dist];
    }

    // lettera maiuscola
    else if (word[i] >= 'A' && word[i] <= 'Z') {
      int dist = word[i] - 'A';
      ++a[dist];
    }
  }

  stampa(a, 26);
  return 0;
}
