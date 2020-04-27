#include "Point.h"

class Vector : public Point {

private:
    Point a;
    Point b;

public:
    Vector(Point a, Point b);

    Vector(double x, double y, double z);

    Vector();
};
