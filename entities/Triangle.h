#include "Point.h"
#include <math.h>

class Triangle : public Point
{

private:
    Point p1;
    Point p2;
    Point p3;
    double side1;
    double side2;
    double side3;

public:
    Triangle(Point, Point, Point);
    void clasifyTriangle() const;
    double findArea() const;
    double findPerimeter() const;
    Point findCentroid() const;
    bool operator<(Point &);
    bool operator>(Point &);
};
