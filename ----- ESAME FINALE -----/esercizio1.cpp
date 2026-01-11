#include <iostream>
#include <fstream>
using namespace std;

// Inserire la vostra soluzione qui sotto senza usare altre librerie
struct Camera {
 int camere;
 char tipo;
 int letti;
};

void stampa (const int array[], int dim) {
    for (int i = 0; i < 12; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

void stampa_camera (int camere, char tipo, int letti) {
    /*
    for (int i=0; i<7; i++) {
      cout << "prezzo" << "[" << i << "]" << " = " << prezzo[i] << endl;
    }
    */
    cout << camere << " " << tipo << " " << letti << endl;
    return;
}

/*
void calcola_tasso_libero (Camera arr_camera[12], int occupazione_camere[28][12], double & tassi[28]) {

  return;
}

void calcola_ricavo_giornaliero (Camera arr_camera[12], int occupazione_camere[28][12], double & ricaving[28]) {

  return;
}

double calcola_decremento (Camera arr_camera[12], int occupazione_camere[28][12], double ricaving[28]) {
  
  return 0.0;
}

*/

int main(int argc, char * argv[]) {
  fstream alb, feb;

  char str[5];
  int num = 3;
  double ris;

  Camera arr_camera[12];
  int occupazione_camere[28][12];

  double tassi[28];
  double ricaving[28];

  if (argc!=3) {
    cerr << "Usa: ./a.out <file1> <file2>\n";
    exit(0);
  }

  alb.open(argv[1],ios::in);

  if (alb.fail()) {
    cerr << "Il file " << argv[1] << " non esiste\n";
    exit(0);
  }

  feb.open(argv[2],ios::in);

  if (feb.fail()) {
    cerr << "Il file " << argv[2] << " non esiste\n";
    alb.close();
    exit(0);
  }

  
  for (int i=0; i<12; i++) {
    while (alb >> str) {
      arr_camera[i].camere = atoi(str);
      
      
      alb >> str;
      arr_camera[i].tipo = str[0];

      alb >> str;
      arr_camera[i].letti = atoi(str);

      stampa_camera(arr_camera[i].camere, arr_camera[i].tipo, arr_camera[i].letti);
    }
  }

  cout << endl;

  while (feb >> num) {
    for (int i=0; i<28; i++) {
      for (int j=0; j<12; j++) {
        while (feb >> num) {
          occupazione_camere[i][j] = num;
          cout << occupazione_camere[i][j] << " " << endl;
        }
      }
    }
  }

  /*
  calcola_tasso_libero(arr_camera, occupazione_camere, tassi);

  calcola_ricavo_giornaliero(arr_camera, occupazione_camere, ricaving);

  ris = calcola_decremento(arr_camera, occupazione_camere, ricaving);
  */

  alb.close();
  feb.close();

  return 0;
}