#include <iostream>
using namespace std;

int main() {
    // DIchiarazione
    char din, dout;
    int vin, vout;

    // Input
    cout <<"Imetti una lettera minuscola... ";
    cin >> din;

    //Calcoli
    vin = (int)din;
    cout << vin;
    vout = vin-32; //(-32) da minus a Maius, (+32) da minus a Maius
    dout = (char)vout;

    // Output
    cout << "Ecco la lettera Maiuscola... " << dout << endl;

    return 0;
}