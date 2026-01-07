using namespace std;
#include <iostream>

int main ()
{
  int i=0;

  cout << "Sono qui " << endl;

  goto LABEL_EX1;

 LABEL_EX2:
  cout << "Sono dopo il goto" << endl;

 LABEL_EX1:

  cout << "Sono dopo la label" << endl;
  goto LABEL_EX2;

  return 0;
}
