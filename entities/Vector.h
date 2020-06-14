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

	Vector(const Vector&);
	Vector& operator=(const Vector&);
	virtual std::ostream& ins(std::ostream&) const;
	virtual std::istream& ext(std::istream&);
	//Toni
	//vector length function that returns real number sqrt(x^2 + y^2 + z^2)
	double vectorLength();
	//calculating the direction of a vector, returns the vector x/sqrt(x^2 + y^2 + z^2), y/sqrt(x^2 + y^2 + z^2), z/sqrt(x^2 + y^2 + z^2)
	Vector& vectorDirection();
	//check whether vector length is 0
	bool checkVectLength();
	//finding whether there is parallelism between two vectors, to do so we will need another vector to be inputed! 
	bool vectParallelism();
	//findind whether there is perpendicularity between two vectors, to do so once again we will need another vector to be inputed!
	bool vectPerpendicularity();
	//Task 3 - overloading operators 
	Vector operator+(const Vector&);
	Vector operator-(const Vector&);
	double operator*(const Vector&);
	Vector operator^(const Vector&);
	double operator() (Vector&, Vector&);
};

std::ostream& operator<<(std::ostream&, const Vector&);
std::istream& operator>>(std::istream&, Vector&);
Vector operator*(double, const Vector&);