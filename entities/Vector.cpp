#include "Vector.h"

Vector::Vector(double x, double y, double z) : Point(x, y, z) {}

Vector::Vector(Point a, Point b) : Point(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ()) {}

Vector::Vector() {}
