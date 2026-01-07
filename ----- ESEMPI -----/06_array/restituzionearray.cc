using namespace std;
#include <iostream>
#include <iomanip>

const int dim=10;

void printarray (int v[], int dim) {
  for (int i=0;i<dim;i++) 
    cout << " " << setw(3) << v[i] << ", ";
  cout << endl;
}


// NB: "a" allocato staticamente all'esterno della funzione!

// Funzione che restituisce un puntatore ad a[0] che corrisponde a v[0].
int *times(int a[], int k) {  // Chiamo l'array a[] ma in realtà a[]==v[], perchè v[] è un puntatore passato alla funzione.
  for (int i=0; i<dim; i++)
    a[i]=a[i]*k;
  return a; 
}


int main () {
  int v[dim] = {1,2,3,4,5,6,7,8,9,10};
  int * w;
  printarray(v,dim);
  w = times(v,4); // Assegno l'indirizzo di a[0] (array modificato dalla funzione times) al puntatore w.
  printarray(w,dim); // NB: passare ad una funzione un puntatore o un array è UGUALE.
  printarray(v,dim); // NB: l'array di partenza è stato modificato.
  return 0;
}
