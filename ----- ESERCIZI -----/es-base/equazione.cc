#include <iostream>
#include <cmath>
using namespace std;

// CONSEGNA: Trovare le 2 soluzioni dell'equazione di secondo grado.

// NOTA: es. non funziona se eq. ha solo 1 sol o 0 sol.

int main() {
    float a, b, c, delta, x1, x2;

    cout << "Imetti a, b, c (es. 1 -3 2): ";
    cin >> a >> b >> c;

    // pow(b,2) == b alla seconda.
    delta = pow(b,2)-4*a*c;

    // sqrt(delta) == radice quadrata di delta.
    x1 = ( (-b) - sqrt(delta) ) / (2*a);
    x2 = ( (-b) + sqrt(delta) ) / (2*a);

    cout << "Soluzione (es.): "<< x1 << " e " << x2 << endl;

    return 0;
}