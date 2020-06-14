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
    // Type of triangle (acc. to angles and acc. to sides)
    void clasifyTriangle() const;
    // Finds Area of Triangle
    double findArea();
    // Finds Perimeter of Triangle
    double findPerimeter() const;
    // Finds Center of Medians in Triangle
    Point findCentroid() const;
    bool operator<(Point &);
    bool operator>(Point &);
    bool operator==(Point &);
    // Checks if point is within Triangle in 3d plane
    bool pointLiesInTriangle(Point &, std::string);
    // Calculates cross product of 2 vectors, by given 3 points
    double crossProductPoints(Point &, Point &, Point &);

    virtual std::ostream &ins(std::ostream &) const;
    virtual std::istream &ext(std::istream &);
};

std::ostream &operator<<(std::ostream &out, const Triangle &t)
{
    return t.ins(out);
}
std::istream &operator>>(std::istream &in, Triangle &t)
{
    return t.ext(in);
}