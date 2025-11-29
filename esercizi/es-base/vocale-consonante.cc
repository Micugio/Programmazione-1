#include <iostream>
using namespace std;

int main() {
    
    char k;

    cout << "Inserire un carattere alfanumerico: " << endl;
    cin >> k;

    /*
    if (k=='a' || k=='e' || k=='i' || k=='o' || k=='u') {
        cout << "è una vocale" << endl;
    }
    else {
        cout << "è una consonante" << endl;
    */

    if (k>='A' && k<='Z' || k>='a' && k<='z') {
        switch (k) {
            case 'A': case 'E': case 'I': case
        }
        cout << "è una vocale" << endl;
    }
    else {
        cout << "è una consonante" << endl;


    }
    return 0;
}