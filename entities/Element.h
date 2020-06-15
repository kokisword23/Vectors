#pragma once
#include <iostream>
class Element {
private:
    double x;
    double y;
    double z;

protected:
    Element(double , double , double);
    Element();
public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

	virtual std::ostream& ins(std::ostream&) const = 0;
	virtual std::istream& ext(std::istream&) = 0;
};

