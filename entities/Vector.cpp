#include "Vector.h"
#include <cmath>
#include "VectorLengthException.h"
Vector::Vector(double x, double y, double z) : Point(x, y, z) {}

Vector::Vector(Point a, Point b) : Point(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ()) {}

Vector::Vector() {}
Vector::Vector(const Vector& rhs) {
	this->setX(rhs.getX());
	this->setY(rhs.getY());
	this->setZ(rhs.getZ());
}
Vector& Vector::operator=(const Vector& rhs) {
	if (this != &rhs)
	{
		this->setX(rhs.getX());
		this->setY(rhs.getY());
		this->setZ(rhs.getZ());
	}
	return *this;
}

std::ostream& Vector::out(std::ostream& output) const {
	return output << "X: " << getX() << std::endl
		<< "Y: " << getY() << std::endl
		<< "Z: " << getZ() << std::endl;
}
std::istream& Vector::in(std::istream& input) {
	double x, y, z;
	input >> x >> y >> z;
	setX(x);
	setY(y);
	setZ(z);
	return input;
}

std::ostream& operator<<(std::ostream& out, const Vector& rhs) {
	return rhs.out(out);
}
std::istream& operator>> (std::istream& in, Vector& rhs) {
	return rhs.in(in);
}

double Vector::vectorLength() {
	return  sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

Vector& Vector::vectorDirection() {
	
	try
	{
		if (this->checkVectLength())
		{
			//ToDo - to return exception from VectorLengthException class
			throw VectorLengthException();
		}
		else
		{
			this->setX(getX() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
			this->setY(getY() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
			this->setZ(getZ() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		}
	}
	catch (const VectorLengthException& vectorExc)
	{
		std::cerr << vectorExc.what() << std::endl;
		std::cout << "Please enter new values for x,y and z that are not 0 ! \n";
		double num;
		do
		{
			std::cin >> num;
			this->setX(num);
			std::cin >> num;
			this->setY(num);
			std::cin >> num;
			this->setZ(num);
		} while (num != 0);

		this->setX(getX() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setY(getY() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setZ(getZ() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
	}
	
	
	return *this;
}

bool Vector::checkVectLength() {
	if (getX() == 0 && getY() == 0 && getZ() == 0)
		return true;
	else
		return false;
}

bool Vector::vectParallelism() {
	double v1, v2, v3;
	try
	{
		if (this->checkVectLength())
		{
			throw VectorLengthException();
		}
	}
	catch (const VectorLengthException& vectorExc)
	{
		std::cerr << vectorExc.what() << std::endl;
		std::cout << "Please enter new values for x,y and z that are not 0 ! \n";
		int num;
		do
		{
			std::cin >> num;
			this->setX(num);
			std::cin >> num;
			this->setY(num);
			std::cin >> num;
			this->setZ(num);
		} while (num != 0);

		this->setX(getX() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setY(getY() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setZ(getZ() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
	}

	std::cout << "Enter the second vector for us to try to find parallelism (v1,v2,v3 podoubles) : \n";
	try
	{
		std::cin >> v1 >> v2 >> v3;
		if (v1 == 0 && v2 == 0 && v3 == 0)
		{
			throw VectorLengthException();
		}
	}
	catch (const VectorLengthException& vExc)	{
		std::cerr << vExc.what() << std::endl;
		std::cout << "Please enter new values for v1, v2 and v3 that are not 0 ! \n";
		do
		{
			std::cin >> v1;
			std::cin >> v2;
			std::cin >> v3;
		} while (v1 == 0 && v2 == 0 && v3 == 0);
	}
	
	double divisorC = v1 / getX();
	if (getX() * divisorC == v1)
	{
		if (getY() * divisorC == v2)
		{
			if (getZ() * divisorC == v3)
			{
				std::cout << "Your vectors are parallel! \n";
				return true;
			}
		}
	}
	std::cout << "Your vectors are not parallel! \n";
	return false;
}

bool Vector::vectPerpendicularity() {
	double v1, v2, v3;
	try
	{
		if (this->checkVectLength())
		{
			throw VectorLengthException();
		}
	}
	catch (const VectorLengthException& vectorExc)
	{
		std::cerr << vectorExc.what() << std::endl;
		std::cout << "Please enter new values for x,y and z that are not 0 ! \n";
		double num;
		do
		{
			std::cin >> num;
			this->setX(num);
			std::cin >> num;
			this->setY(num);
			std::cin >> num;
			this->setZ(num);
		} while (num != 0);

		this->setX(getX() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setY(getY() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
		this->setZ(getZ() / sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2)));
	}

	std::cout << "Enter the second vector for us to try to find perpendicularity (v1,v2,v3 points) : \n";
	try
	{
		std::cin >> v1 >> v2 >> v3;
		if (v1 == 0 && v2 == 0 && v3 == 0)
		{
			throw VectorLengthException();
		}
	}
	catch (const VectorLengthException& vExc) {
		std::cerr << vExc.what() << std::endl;
		std::cout << "Please enter new values for v1, v2 and v3 that are not 0 ! \n";
		do
		{
			std::cin >> v1;
			std::cin >> v2;
			std::cin >> v3;
		} while (v1 == 0 && v2 == 0 && v3 == 0);
	}

	if ((getX()*v1) + (getY()*v2) + (getZ()*v3) == 0)
	{
		std::cout << "Your vectors are perpendicular! \n";
		return true;
	}

	std::cout << "Your vectors are not perpendicular! \n";
	return false;
}

Vector Vector::operator+(const Vector& v2) {
	Vector sum;
	sum.setX(this->getX() + v2.getX());
	sum.setY(this->getY() + v2.getY());
	sum.setZ(this->getZ() + v2.getZ());
	return sum;
}

Vector Vector::operator-(const Vector& v2) {
	Vector diff;
	diff.setX(this->getX() - v2.getX());
	diff.setY(this->getY() - v2.getY());
	diff.setZ(this->getZ() - v2.getZ());
	return diff;
}

Vector operator*(double realNum, const Vector& vect) {
	Vector product;
	product.setX(realNum * vect.getX());
	product.setY(realNum * vect.getY());
	product.setZ(realNum * vect.getZ());
	return product;
}

double Vector::operator*(const Vector& vect2) {

	double realNum;
	realNum = this->getX() * vect2.getX() + this->getY() * vect2.getY() + this->getZ() * vect2.getZ();
	return realNum;
}

Vector Vector::operator^(const Vector& vect2) {
	Vector product;
	product.setX(this->getX() * vect2.getX());
	product.setY(this->getY() * vect2.getY());
	product.setZ(this->getZ() * vect2.getZ());
	return product;
}


double Vector::operator() (Vector& v, Vector& w) {
	double x = 0, y = 0, z = 0;
	x = v.getY() * w.getZ() - w.getY() * v.getZ();
	std::cout << "X =" << x << std::endl;
	y = w.getY() * this->getZ() - this->getY() * w.getZ();
	std::cout << "Y =" << y << std::endl;
	z = this->getY() * v.getZ() - v.getY() * this->getZ();
	std::cout << "Z =" << z << std::endl;
	return (this->getX() * x) + (v.getX() * y) + (w.getX() * z);
}
