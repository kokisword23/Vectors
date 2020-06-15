#include "Tetrahedron.h"
#include "EqualPointsException.h";

Tetrahedron::Tetrahedron(Point p1, Point p2, Point p3, Point p4)
{
    if (p1 == p2)
        throw EqualPointException("ERROR: Equal points (Point \"A\" and Point \"B\").");
    else if (p2 == p3)
        throw EqualPointException("ERROR: Equal points (Point \"B\" and Point \"C\").");
    else if (p3 == p4)
    {
        throw EqualPointException("ERROR: Equal points (Point \"C\" and Point \"D\").");
    }
    else if (p1 == p3)
        throw EqualPointException("ERROR: Equal points (Point \"A\" and Point \"C\").");
    else if (p1 == p4)
        throw EqualPointException("ERROR: Equal points (Point \"A\" and Point \"D\").");
    else if (p1 == p2 && p2 == p3)
        throw EqualPointException("ERROR: Equal points (Point \"A\", Point \"B\" and Point \"C\").");
    else if (p2 == p3 && p3 == p4)
        throw EqualPointException("ERROR: Equal points (Point \"B\", Point \"C\" and Point \"D\").");
    else if (p1 == p2 && p2 == p3 && p3 == p4)
    {
        throw EqualPointException("ERROR: All points are equals.");
    }

    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;
}
bool Tetrahedron::isTetrahedronRight()
{
    return false;
}
bool Tetrahedron::isTetrahedronOrtagonal()
{
    return false;
}
double Tetrahedron::findSurroundingSurface()
{
    Triangle a(p1, p2, p3);
    Triangle b(p1, p4, p3);
    Triangle c(p2, p4, p3);
    Triangle d(p1, p2, p4);
    float res = a.findArea() + b.findArea() + c.findArea() + d.findArea();
    return res;
}
double Tetrahedron::findVolume()
{
    Vector a(p1, p2);
    Vector b(p1, p3);
    Vector c(p1, p4);
    float temp = a.operator()(b, c);
    return (temp / 6);
}
bool Tetrahedron::operator<(Point &p)
{
    return false;
}
bool Tetrahedron::operator>(Point &p)
{
    return false;
}
bool Tetrahedron::operator==(Point &p)
{
    return false;
}

std::ostream &Tetrahedron::ins(std::ostream &out) const
{
    out << "Tetrahedron(Point1): " << endl
        << p1 << "Tetrahedron(Point2): " << endl
        << p2 << "Tetrahedron(Point3): " << endl
        << p3 << "Tetrahedron(Point4): " << endl
        << p4 << endl;
    return out;
}
std::istream &Tetrahedron::ext(std::istream &in)
{
    in >> p1;
    in >> p2;
    in >> p3;
    in >> p4;

    return in;
}
