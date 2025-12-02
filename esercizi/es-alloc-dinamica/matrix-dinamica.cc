#include <iostream>
#include <cstdlib>
using namespace std;

// Matrice dimamica con dimensioni passare tramite parametri da riga di comando.

int **generate_matrix(int rows, int cols) {
  // Alloco la memoria necessaria per la matrice, alloco l'array per le righe
  int **matrix = new int *[rows];

  for (int i = 0; i < rows; i++) {
    //per ogni riga alloco un array per le colonne
    matrix[i] = new int[cols];
  }

  // Riempio la matrice con i valori necessari
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 100;
    }
  }

  return matrix;
}


int main(int argc, char *argv[]) {
  srand(time(NULL)); // Inizializzo il generatore di numeri casuali

  // Controllo degli argomenti
  if (argc != 3) {
    cout << "Usage: random-matrix <rows> <cols>" << endl;
    exit(0);
  }

  // Ottengo la grandezza dell'array e lo genero
  int rows = atoi(argv[1]); // NB: Converte una stringa in int.
  int cols = atoi(argv[2]); // NB: Converte una stringa in int.
  int **matrix = generate_matrix(rows, cols);

  // Stampo a video il contenuto della matrice
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;

  // IMPORTANTE! Dealloco la matrice allocata in generate_matrix prima di uscire
  for (int i = 0; i < rows; i++) {
    delete[] matrix[i]; //per ogni riga dealloco l'array delle sue colonne
  }

  delete[] matrix; //dealloco l'array che conteneva le righe

  return 0;
}
