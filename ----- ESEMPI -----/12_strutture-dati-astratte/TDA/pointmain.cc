#include <iostream>
using namespace std;
#include "point.h"


// COMPILARE CON: g++ point.cc pointmain.cc


// OPPURE CON: g++ -c pointmain.cc  (NOTA: crea file oggetto, in queso modo non usa linker del compilatore)

// Se voglio NON USARE (g++ -c pointmain.cc):
// #include "point.cc"
// Al posto di (#include "point.h"), POI compilo con (g++ pointmain.cc)

int main() {
  double t;
  Point P2, P1, P3;
  P1.x = 40;
  P1 = PointInit(5.0, 5.0);

  Point_Print(P1, "Coordinate del Punto P1");
  cout << "Inserire coordinate di un Punto P2" << endl << "X = " ;
  cin >> t;
  Point_SetX(P2, t);
  cout << "Y = "; cin >> t;
  Point_SetY(P2, t);
  cout << "La distanza tra P1 e P2 e': " << Point_GetDistance(P1, P2) << endl;
  if (Point_Equal(P1, P2)) {
    P3 = Point_Sum(P1, P2);
  }
  else {
    P3 = PointInit(1.0, 1.0);
  }
  Point_Print(P3, "Coordinate del Punto P3");
  if (Point_Aligned(P1, P2, P3)) {
    cout << "I tre punti risiedono su una retta" << endl;
  }
  else {
    cout << "I tre punti non risiedono su una retta" << endl;
  }
}
