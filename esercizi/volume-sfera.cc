#include <iostream>
using namespace std;

int main()
{
	const float pigreco = 3.14;
	float raggio = 0.0;
	float volume = 0.0;
	cout << "inserisci il raggio di una sfera: ";
	cin >> raggio;
	if (raggio <0){
		cerr << "ERRORE: il raggio non può essere minore di zero" << endl;
	}
	volume = pigreco*(4/3)*raggio*raggio*raggio;
	cout << "la sfera di raggio "<< raggio << " ha volume : "<< volume << endl;
	return 0;
}
