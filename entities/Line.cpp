#include "Line.h"
#include <cmath>

Line::Line(Point a, Point b) : Vector(a, b) {}

Line::Line(Point a, Vector v) : Vector(v) {}


// Return vector parallel to a line
Vector Line::lineDirection() {
    return Vector(this->getX(), this->getY(), this->getZ());
}

//Return vector from parallel
Vector Line::normalVector() {
    Vector result = Vector();
    Vector vector(this->a.getX(), this->a.getY(), this->a.getZ());
    result = lineDirection() ^ vector;
    return result;
}

// Return the angle between two lines
double Line::angle(Line line) {
    return (this->getZ() * this->getY() + this->getX() * line.getX()) / (line.vectorLength() * this->vectorLength());
}

// Check if point is laying on a line
bool Line::operator+(const Point &point) const {
    return ((point.getX() >= this->a.getX() && point.getX() <= this->b.getX()) ||
             (point.getY() >= this->a.getY() && point.getY() <= this->b.getY()) ||
              (point.getZ() >= this->a.getZ() && point.getZ() <= this->b.getZ()));

//    return (point.getX() - this->a.getX() / this->b.getX() ==
//           (point.getY() - this->a.getY() / this->b.getY()) ==
//           (point.getZ() - this->a.getZ() / this->b.getZ()));
}


// Check if 2 lines are parallel
bool Line::operator||(Line line) {
    return (this->vectorDirection() ^ line.lineDirection()).vectorLength() == 0;
}

// Check if 2 lines are equal
bool Line::operator==(Line line) {
    return (this->a.getX() == line.getX() &&
            this->a.getY() == line.getY() &&
            this->a.getZ() == line.getZ() &&
            this->lineDirection() == line.lineDirection());
}

// Check if line is crossing another line
bool Line::operator&&(const Line &line) {
    return (this->a.getX() == line.getX() ||
            this->a.getY() == line.getY() ||
            this->a.getZ() == line.getZ());
}

// Check if two lines intersect
bool Line::operator!=(const Line &line) {
    return ((this->b.getX() <= fmax(this->a.getX(), line.getX() && fmin(this->a.getX(), line.getX()))) &&
            (this->b.getY() <= fmax(this->a.getY(), line.getY() && fmin(this->a.getY(), line.getY()))));
}

// Check if line is perpendicular to another line
bool Line::operator|(const Line &) {
    return (this->lineDirection().vectParallelism());
}

//    Point a;
//    Point b;
//    Vector v;
std::ostream &Line::ins(std::ostream &out) const
{
    out << "Line(Point1): " << std::endl
        <<  a<< "Line(Point2): " << std::endl
        << b << "Line(Vector): " << std::endl
        << v;
    return out;
}
std::istream &Line::ext(std::istream &in)
{
    in >> a;
    in >> b;
    in >> v;

    return in;
}

