#include <cmath>
#include <iostream>

using namespace std;

#include "point.h"

Point PointInit() {
#if NOT_USE_ARRAY
  Point r = {0.0, 0.0};
#else
  Point r;
  r.coord[0] = 0.0;
  r.coord[1] = 0.0;
#endif
  return r;
}

Point PointInit(const double x, const double y) {
#if NOT_USE_ARRAY
  Point r = {x, y};
#else
  Point r;
  r.coord[0] = x;
  r.coord[1] = y;
#endif
  return r;
}

// Ritorna la coordinate X e Y di P
double Point_GetX(const Point & p) {
#if NOT_USE_ARRAY
  return p.x;
#else
  return p.coord[0];
#endif
}

double Point_GetY(const Point & p) {
#if NOT_USE_ARRAY
  return p.y;
#else
  return p.coord[1];
#endif
}

// Assegna le coordinate X e Y di P
void Point_SetX(Point & p, const double x) {
#if NOT_USE_ARRAY
  p.x = x;
#else
  p.coord[0] = x;
#endif
}

void Point_SetY(Point & p, const double y) {
#if NOT_USE_ARRAY
  p.y = y;
#else
  p.coord[1] = y;
#endif
}

// Predicato per controllare se due Punti sono uguali
bool Point_Equal(const Point & P1, const Point & P2) {
  return ((Point_GetX(P1) == Point_GetX(P2)) &&
	  (Point_GetY(P1) == Point_GetY(P2)));
}

// Stampa coordinate di un punto P inserendo
// la stringa n prima della stampa delle coordinate
void Point_Print(const Point & P, const char * n) {
  cout << n << endl;
  cout << ".X = " << Point_GetX(P) << endl;
  cout << ".Y = " << Point_GetY(P) << endl;
}


// calcola la distanza tra due punti
double Point_GetDistance(const Point & P1,
			  const Point & P2) {
  double dx = (Point_GetX(P1) - Point_GetX(P2));
  double dy = (Point_GetY(P1) - Point_GetY(P2));

  return sqrt(dx * dx + dy * dy);
}

// Costruisci il punto risultante dalla somma delle
// rispettive coordinate di due punti P1 e P2
Point Point_Sum(const Point & P1,
		const Point & P2) {
  return PointInit(Point_GetX(P1) + Point_GetX(P2),
		   Point_GetY(P1) + Point_GetY(P2));
}

bool Point_Aligned(const Point & P1, const Point & P2,
                   const Point & P3) {
  return ((Point_GetY(P1) - Point_GetY(P2)) *
	  (Point_GetX(P1) - Point_GetX(P3))) ==
    ((Point_GetY(P1) - Point_GetY(P3)) *
     (Point_GetX(P1) - Point_GetX(P2)));
}
