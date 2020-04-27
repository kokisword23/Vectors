#include "Point.h"

Point::Point(double x, double y, double z) : Element(x, y, z) {}

bool Point::operator==(Point point) {
    bool statement = this->getX() == point.getX() && this->getY() == point.getY() && this->getZ() == point.getZ();
    return statement;
}

Point::Point() {}
