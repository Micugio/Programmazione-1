#include <iostream>
using namespace std;
/* RICORDA
Maiuscole = minore di 91
minuscole = maggiore di 91

valore booleano: true=1 false=0
*/
int main() {
    // Dichiarazione
    char din, dout;
    int vin, vout;
    bool flag;

    // Input
    cout <<"Imetti una lettera Maiuscola o minuscola... ";
    cin >> din;
    
    //Calcoli e controllo
    vin = (int)din;
    flag = (vin<91); // vale 1 se Maiuscola, vale 0 se minuscola

    vout = (vin+32)*flag + (vin-32)*(1-flag);
    dout = (char)vout;

    // Output
    cout << "Ecco la lettera opposta... " << dout << endl;

    return 0;
}