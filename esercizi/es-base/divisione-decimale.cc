#include <iostream>
using namespace std;

int main(){
	int dividendo;
	int divisore;
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
	
	int resto = dividendo % divisore;
	quoziente = (dividendo-resto)/divisore;
	
	cout << "il modulo della divisione è: " << quoziente << endl;
	cout << "il resto della divisione è: " << resto << endl;
	return 0;
}
