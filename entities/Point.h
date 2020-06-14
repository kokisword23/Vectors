#include "Element.h"
#include <iostream>
class Point : public Element {
public:
    Point(double x, double y, double z);

    Point();

    bool operator == (Point point);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Point&);
std::istream& operator>>(std::istream&, Point&);