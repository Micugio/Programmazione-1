#include <fstream>
#include <iostream>

using namespace std;

const int MAX = 1000; // dimensione massima dei file

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Numero di argomenti errato\n";
        return 1;
    }

    ifstream f1(argv[1]);
    ifstream f2(argv[2]);
    ofstream out(argv[3]);

    if (!f1 || !f2) {
        cerr << "Errore apertura file\n";
        return 1;
    }

    char a1[MAX], a2[MAX];
    int len1 = 0, len2 = 0;
    char c;

    // Lettura primo file
    while (len1 < MAX && f1.get(c)) {
        a1[len1++] = c;
    }

    // Lettura secondo file
    while (len2 < MAX && f2.get(c)) {
        a2[len2++] = c;
    }

    // Alternanza
    int i = 0;
    while (i < len1 || i < len2) {
        if (i < len1) out.put(a1[i]);
        if (i < len2) out.put(a2[i]);
        i++;
    }

    return 0;
}
