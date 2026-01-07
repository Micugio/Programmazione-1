#include <iostream>
#include "caesar.h"
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
    fstream myin,myout;
    char c;
    
    if (argc!=3) {
        cout << "Usage: ./a.out <sourcefile> <targetfile>\n";
        exit(0);
    }

    myin.open(argv[1],ios::in);
    if (myin.fail()) {
        cerr << "Il file " << argv[1] << " non esiste\n";
        exit(0);
    }

    myout.open(argv[2],ios::out|ios::app); // NOTA: file aperto in scrittura append
    if (myout.fail()) {
        myin.close(); // Fondamentale CHIUDERE STREAM dopo che ho letto
        cerr << "Il file " << argv[2] << " non e' scrivibile\n";
        exit(0);
    }
    
    char parola [256];
    int chiave = 3;
    int scelta = 0;

    while (myin.getline(parola,256)) { // Uguale a "copiafile.cc" solo che carattere vengono copiati in append
        cout << "Vuoi criptare o decriptare? (Inserisci rispettivamente 0 o 1)" << endl;
        cin >> scelta;
        if (scelta==0) {
            parola[i] = 
        }
        
        else (scelta==1) {
            
        }
        
        myout.put(c);
    }
    myin.close();
    myout.close();
    int chiave = 3;
    crypt(parola, chiave);

    return 0;
}