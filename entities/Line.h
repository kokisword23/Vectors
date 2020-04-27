
#include "Vector.h"

class Line : public Vector {

private:
    Point a;
    Point b;
    Vector v;
public:
    Line(Point a, Point b);

    Line(Point a, Vector v);
};