#include <iostream>
using namespace std;

void mySwap (int* pa, int* pb) {
    int t = 0;
    t = *pa;
    *pa = *pb;
    *pb = t;
}

int main() {
    int a = 5;
    int b = 10;

    cout << a << endl;
    cout << b << endl;
    cout << endl;

    mySwap (&a, &b);

    cout << a << endl;
    cout << b << endl;
    

    return 0;
}