// Definizione dell'ADT Point
typedef struct Point_ Point;

#define NOT_USE_ARRAY 1

// struct Point_;

struct Point_ {
#if NOT_USE_ARRAY
  // Prima implementazione
  double x;
  double y;
#else
  // Seconda implementazione
  double coord[2];
#endif
};


// Definizione dei metodi dell'ADT Point
Point PointInit(void);
Point PointInit(const double x, const double y);
double Point_GetX(const Point & p);
double Point_GetY(const Point & p);
void Point_SetX(Point & p, double x);
void Point_SetY(Point & p, double y);
bool Point_Equal(const Point & P1, const Point & P2);
void Point_Print(const Point & P, const char * n);
double Point_GetDistance(const Point & P1, const Point & P2);
Point Point_Sum(const Point & P1, const Point & P2);
bool Point_Aligned(const Point & P1, const Point & P2,
                   const Point & P3);
