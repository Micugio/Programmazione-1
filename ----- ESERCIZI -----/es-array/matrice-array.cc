#include <iostream>
using namespace std;

int main() {
    
    int matrice[3][6] = {
        {0,0,0,0,0,0},
        {1,1,1,1,1,1},
        {0,0,0,0,0,0}
    };

    for (int i=0; i<3; i++){
        for (int j=0; j<6; j++){
            cout << matrice[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}