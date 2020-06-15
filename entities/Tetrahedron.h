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

public:
    Tetrahedron(Point, Point, Point, Point);
    bool isTetrahedronRight();
    bool isTetrahedronOrtagonal();
    double findSurroundingSurface();
    double findVolume();
    bool operator<(Point &);
    bool operator>(Point &);
    bool operator==(Point &);
    virtual std::ostream &ins(std::ostream &) const;
    virtual std::istream &ext(std::istream &);
};

std::ostream &operator<<(std::ostream &out, const Tetrahedron &t)
{
    return t.ins(out);
}
std::istream &operator>>(std::istream &in, Tetrahedron &t)
{
    return t.ext(in);
}