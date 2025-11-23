#include <iostream>
using namespace std;

double jump () {
    double salto = 0;
    do {
        salto = rand();
    } while (salto<1.0 || salto>3.0);

    return salto;
}

int round (double salto1, double salto2, double salto3) {
    int vincitoreRound = 0;
    if (salto1>=salto2){
        if (salto1>=salto3) {
            vincitoreRound = 1;
            return vincitoreRound;
        }
    }
    else if (salto2>=salto3) {
        vincitoreRound = 2;
        return vincitoreRound;
    }
    else {
        vincitoreRound = 3;
        return vincitoreRound;
    }
    return vincitoreRound;
}


int main() {
    srand(time(NULL));
    
    //double salto1 = jump();
    double salto1 = 2.9;
    cout << "salto1 = " << salto1 << endl;

    //double salto2 = jump();
    double salto2 = 2.5;
    cout << "salto2 = " << salto2 << endl;

    //double salto3 = jump();
    double salto3 = 2.0;
    cout << "salto3 = " << salto3 << endl;

    cout << "vincitoreRound = " << round (salto1, salto2, salto3) << endl;




    return 0;
}