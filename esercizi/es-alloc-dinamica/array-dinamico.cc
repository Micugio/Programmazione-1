#include <iostream>
#include <cstdlib>
using namespace std;


int * generate_numbers(int length) {
  //Alloco arrayDyna nella memoria dinamica, tale spazio di memoria sopravvive allo scope della funzione, ovvero rimane fino al suo delete
  int *arrayDyna = new int[length];

  for (int i = 0; i < length; i++) {
    arrayDyna[i] = rand() % 100;
  }

  return arrayDyna;
}


int main(int argc, char *argv[]) {
  srand(time(NULL)); // Inizializzo il generatore di numeri casuali

  // Controllo degli argomenti
  if (argc != 2) {
    cout << "Usage: random-arrayDyna <length>" << endl;
    exit(0);
  }

  // Ottengo la grandezza dell'arrayDyna e lo genero
  int length = atoi(argv[1]); // NB: Converte una stringa in int.
  int *array = generate_numbers(length);

  // Stampo a video il contenuto dell'arrayDyna
  for (int i = 0; i < length; i++) {
    cout << array[i] << " ";
  }
  cout << endl;

  // IMPORTANTE! Prima di terminare il programma dealloco l'array generato nella funzione generate_numbers.
  // Il puntatore array nel main punta allo stesso spazio di memoria di arrayDyna.
  delete[] array;

  return 0;
}
