#include <iostream>
#include <cstdlib>
using namespace std;

double jump ();
int round (double saltoA, double saltoB, double saltoC);
void podium (int A, int B, int C);

int main() {
    int A = 0;
    int B = 0;
    int C = 0;

    double saltoA, saltoB, saltoC;

    for (int i=0; i<10; i++) {
        saltoA = jump();
        saltoB = jump();
        saltoC = jump();

        
        if (round(saltoA, saltoB, saltoC) == A) {
            ++A;
        }
        if (round(saltoA, saltoB, saltoC) == B) {
            ++B;
        }
        if (round(saltoA, saltoB, saltoC) == C) {
            ++C;
        }
    }
    
    podium(A, B, C);

    return 0;
}

double jump () {
    double salto;

    srand(time(NULL));

    /*
    rand() % 201 → numero tra 0 e 200
    +100 → numero tra 100 e 300
    (double) → trasformiamo in decimale
    /100 → scala tra 1.0 e 3.0
    */
    salto = (double)(rand() % 201 + 100) / 100;

    return salto;
}


int round (double saltoA, double saltoB, double saltoC) {
    int risultato;
    if (saltoA > saltoB) {
        if (saltoA > saltoC) {
            risultato = A;
        }
    }
    else if (saltoB > saltoC) {
        risultato = B;
    }
    else {
        risultato = C;
    }
    return risultato;
}

void podium (int A, int B, int C) {
    if (A > B) {
        if (A > C) {
            cout << "Primo posto A con punti... " << A << endl;
            if (B > C) {
               cout << "Secondo posto B con punti... " << B << endl;
               cout << "Terzo posto C con punti... " << C << endl; 
            }
            else {
                cout << "Secondo posto C con punti... " << C << endl;
                cout << "Terzo posto B con punti... " << B << endl; 
            }
        }
    }
    else if (B > C) {
        cout << "Primo posto B con punti... " << B << endl;
        if (A > C) {
            cout << "Secondo posto A con punti... " << A << endl;
            cout << "Terzo posto C con punti... " << C << endl; 
        }
        else {
            cout << "Secondo posto C con punti... " << C << endl;
            cout << "Terzo posto A con punti... " << A << endl; 
        }
    }
    else {
        cout << "Primo posto C con punti... " << C << endl;
        if (A > B) {
            cout << "Secondo posto A con punti... " << A << endl;
            cout << "Terzo posto B con punti... " << B << endl;
        }
        else {
            cout << "Secondo posto B con punti... " << B << endl;
            cout << "Terzo posto A con punti... " << A << endl;
        }
    }
}
