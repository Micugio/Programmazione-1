#include <iostream>
using namespace std;

int main() {
    char ingresso,uscita;
    bool flag,flag1,flag2;
    
    cout << "Immetti una lettera: ";
    cin >> ingresso;
    
    flag = (ingresso<'a');
    flag1 = (ingresso<'A') + (ingresso>'Z') * (ingresso <'a') + (ingresso>'z');
    flag1 = 1-flag1;
    uscita = (ingresso+'a'-'A')*flag*flag1+(ingresso+'A'-'a')*(1-flag)*flag1+ '?'*(1-flag1);

    cout << uscita << endl;
    return 0;
}
