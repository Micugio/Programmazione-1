#include <iostream>
using namespace std;

int main(){
	int minuti, ore,secondi;
    cout << "Inserisci secondi:" << endl;
	cin >> secondi;
	ore = secondi / 3600;
	secondi -= ore*3600;
	ore = ore%24;
	minuti = (secondi)/60;
	secondi -= minuti*60;
	cout << (char)((ore<10)*'0')<< ore << ':' << (char)((minuti<10)*'0')<< minuti <<':' <<(char)((secondi<10)*'0')<< secondi << endl;

}