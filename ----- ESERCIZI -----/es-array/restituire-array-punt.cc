#include <iostream>
using namespace std;

void creaArrayBool(bool* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = (i % 2 == 0);  // Imposta ogni elemento alternato come true/false
    }
}

int main() {
    const int size = 5;
    bool arr[size];  // Array di dimensione fissa

    creaArrayBool(arr, size);

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
