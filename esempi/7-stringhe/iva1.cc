using namespace std;
#include <iostream>
#include <cstdlib>

void aggiungi_iva(float & val, float  iva) 
{
  val *= 1.0 + iva/100.0;
}

int main (int argc, char * argv[]) 
{
  float aliquota = 22;
  float val;

  if (argc==1){   //(input nessun argomento)
    cout << "Valore? ";
    cin >> val;
  }
  else if (argc == 2) {  //(input un argomento: il valore)
    val = atof(argv[1]); // NB: Converte una stringa in double.
  }
  else if (argc == 3) {   //(input due argomenti: il valore e l'aliquota)
    val = atof(argv[1]); // NB: Converte una stringa in double.
    aliquota = atof(argv[2]); // NB: Converte una stringa in double.
  }
  else {
    cout << "Troppi argomenti!!!\n";
    cout << "Formato: \n";
    cout << "./a.out  \n";
    cout << "./a.out <valore>\n";
    cout << "./a.out <valore> <aliquota>\n";
    return 0;
  }
  aggiungi_iva(val, aliquota);
  cout << "Nuovo valore = " << val << endl;
  return 0;
}
