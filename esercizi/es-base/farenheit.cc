#include <iostream>
using namespace std;

float convert(float temperatura_farenheit){
	const int conversione1 = 32;
	const float conversione2 = 1.8;
	return (temperatura_farenheit - conversione1)/conversione2;
}

int main()
{
	float farenheit = 0.0;
	float celsius = 0.0;
	cout << "inserire la temperatura in farenheit: ";
	cin >> farenheit;
	celsius = convert(farenheit);
	cout << "la temperatura in celsius vale: " << celsius << endl;
	return 0;

}
