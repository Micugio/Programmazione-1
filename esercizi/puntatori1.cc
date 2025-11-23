#include <iostream>
using namespace std;

int main() {
    int x = 22;
    int &ptr = x;

    cout << ptr << endl;
    
    return 0;
}