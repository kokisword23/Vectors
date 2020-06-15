#include "Point.h"
#include "Triangle.h"
#include "Vector.h"
#include <math.h>

class Tetrahedron : public Point
{

private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;

    Tetrahedron(Point, Point, Point, Point);
    bool isTetrahedronRight();
    bool isTetrahedronOrtagonal();
    double findSurroundingSurface();
    double findVolume();
    bool operator<(Point &);
    bool operator>(Point &);
    bool operator==(Point &);
};