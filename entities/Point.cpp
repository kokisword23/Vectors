#include "Point.h"

Point::Point(double x, double y, double z) : Element(x, y, z) {}

bool Point::operator==(Point point) {
    bool statement = this->getX() == point.getX() && this->getY() == point.getY() && this->getZ() == point.getZ();
    return statement;
}

Point::Point() {}

std::ostream& Point::ins(std::ostream& out) const {
	return out << "X: " << getX() << std::endl
		<< "Y: " << getY() << std::endl
		<< "Z: " << getZ() << std::endl;
}
std::istream& Point::ext(std::istream& in) {
	double x, y, z;
	in >> x;
	this->setX(x);
	in >> y;
	this->setY(y);
	in >> z;
	this->setZ(z);

	return in;
}

std::ostream& operator<<(std::ostream& lhs, const Point& rhs) {
	return rhs.ins(lhs);
}
std::istream& operator>>(std::istream& lhs, Point& rhs) {
	return rhs.ext(lhs);
}
