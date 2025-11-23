#include <iostream>
using namespace std;

int main(){
	float dividendo;
	float divisore;
	int quoziente = 0;

	cout << "inserire il dividendo: "; 
	cin >> dividendo;
	cout << "inserire il divisore: ";
	cin >> divisore;

	if (divisore==0)
	{
		cerr << "ERRORE: non si può dividere per 0!!!";
		return 1;
	}
	
	while (dividendo>=divisore){
		dividendo -= divisore;
		quoziente +=1;
	}
	cout << "il modulo della divisione è: " << quoziente << endl;
	cout << "il resto della divisione è: " << dividendo << endl;
	return 0;
}
