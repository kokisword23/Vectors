#include "Point.h"

class Triangle : public Point {

private:
    Point a;
    Point b;
    Point c;

public:
    Triangle(Point a,Point b, Point c);
};
