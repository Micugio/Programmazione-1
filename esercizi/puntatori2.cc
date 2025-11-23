#include <iostream>
using namespace std;

int main() {
    double x, *pd, **hp;

    cin >> x;

    pd = &x; //inizializzo puntatore che punta a x (prende indirizzo di x)
    cout << "valore puntatore pd: " << *pd << endl; //stampa valore puntatore quindi valore di x
    *pd = 2*(*pd);
    cout << x << endl;

    hp = &pd;
    **hp = (**hp)/5;
    cout << x << endl;

    return 0;
}

// ALTRO MODO IDENTICO, cambia solo formattazione
/*
int main() {
    double n = 5;
    double *p = &n;
    double **q = &p;

    cout << n << endl;
    
    *p = (*p)*2;
    cout << *p << endl;

    **q = (**q)/5;
    cout << **q << endl;

    return 0;
}
*/
