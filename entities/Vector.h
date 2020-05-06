#include "Point.h"
#include <iostream>
class Vector : public Point {

private:
    Point a;
    Point b;

public:
    Vector(Point a, Point b);

    Vector(double x, double y, double z);

    Vector();

	//Toni
	//vector length function that returns real number sqrt(x^2 + y^2 + z^2)
	double vectorLength();
	//calculating the direction of a vector, returns the vector x/sqrt(x^2 + y^2 + z^2), y/sqrt(x^2 + y^2 + z^2), z/sqrt(x^2 + y^2 + z^2)
	Vector& vectorDirection();
	//check whether vector length is 0
	bool checkVectLength();

};
