#include <iostream>
#include "Vector.h"

class Line : public Vector {

private:
    Point a;
    Point b;
    Vector v;
public:
    Line(Point a, Point b);

    Line(Point a, Vector v);

	//Toni
	//function finding the direction of a line - returns a vector parallel to the line;
	Vector lineDirection();
	Vector normalVector();
	double angle(Line);

	bool operator+(const Point&) const;
	bool operator||(Line);
	bool operator==(Line);
	bool operator&&(const Line&);
	bool operator!=(const Line&);
	bool operator|(const Line&);

	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Line&);
std::istream& operator>>(std::istream&, Line&);