#include <iostream>
using namespace std;


int  found, loc, target;

void inizializza (int array[], int dim) {
  cout << "Inserisci valori interi:" << endl;
  for (int i=0; i<dim; i++) {
    cout << "a[" << i << "]: ";  
    cin >> array[i];
  }
  return;
}

void stampa (const int array[], int dim) {
  for (int i=0; i<dim; i++) {
    cout << "a[" << i << "]: " << array[i] << endl;
  }
  return;
}

void scambia(int & n,int & m)
{
  int t;
  t=n;
  n=m;
  m=t;
  return;
}

// Insertion Sort
void insertionsort(int array[], int dim) {
  for(int i = dim-1; i > 0; i--)
    if (array[i] < array[i-1]) {
      scambia(array[i],array[i-1]);
    }

  for(int i = 2; i <= dim-1; i++) {
    int j = i;
    int v = array[i];
    while(v < array[j-1]) {
      array[j] = array[j-1]; j--;
    }
    array[j] = v;
  }
}

// Selection Sort
void selectionsort(int array[], int dim) {
for(int i = 0; i < dim - 1; i++ ){
  int min = i;
  for(int j = i+1; j < dim; j++) {
    if (array[j] < array[min]) min = j;
  }
  scambia(array[i],array[min]);
  }
  return;
}

//  Ricerca binaria:
int search(const int array[], int dim, int target)
{
  bool found=false;
  int location, left = 0, right = dim-1;
  while (!found && left <= right) {
    location = (left + right)/2;  
    if (array[location] == target)
      found = true;
    else if (array[location] < target) 
      left = location + 1;
    else 
      right = location - 1;
  }
  return (found ? location : -1);
}

int main() {
  const int dim = 6;
  int array[dim];

  inizializza (array, dim);
  insertionsort(array, dim);
  cout << endl;
  stampa (array, dim);

  do {
  cout << '\t' << "Target: ";  
  cin >> target;
  loc = search(array, dim, target);
  if (loc>=0) {
    cout << '\t' << target << " è nella posizione a[" << loc << "].\n\n";
  }
  else {
    cout << '\t' << target << " non trovato.\n\n";
  }
  } while (target >= 0);

  return 0;
}





