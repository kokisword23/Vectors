#include "Element.h"

Element::Element(double x, double y, double z) : x(x), y(y), z(z) {}

double Element::getX() const {
    return x;
}

void Element::setX(double x) {
    Element::x = x;
}

double Element::getY() const {
    return y;
}

void Element::setY(double y) {
    Element::y = y;
}

double Element::getZ() const {
    return z;
}

void Element::setZ(double z) {
    Element::z = z;
}

Element::Element() {}
