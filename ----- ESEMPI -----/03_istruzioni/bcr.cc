using namespace std;

#include <iostream>

int main() {
  char c;
  cout << "Vuoi testare continue (c), break (b) o return (r) [c,b,r]? ";
  cin >> c;

  for(int i = 0; i<5; i++) {
    for(int j = 0; j < 5; j++) {
      cout << "prima del salto i,j = (" << i << "," << j << ")" << endl;
      if (c == 'c')  {
	if (i+j == 3) continue;
      }
      else if (c == 'b') {
	if (i+j == 3) break;
      }
      else if (c == 'r') {
	if (i+j == 3) return 0;
      }
      else {
	cout << "Carattere sconosciuto! Default to return" << endl;
	if (i+j == 3) return 0;
      }
      cout << "dopo il salto     i,j = (" << i << "," << j << ")" << endl;
    }
    cout << "i = (" << i << ")" << endl;
  }
}
