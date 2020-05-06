#include "Vector.h"
#include <cmath>
#include "VectorLengthException.h"
Vector::Vector(double x, double y, double z) : Point(x, y, z) {}

Vector::Vector(Point a, Point b) : Point(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ()) {}

Vector::Vector() {}

double Vector::vectorLength() {
	return  sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(getZ(), 2));
}

Vector& Vector::vectorDirection() {
	Vector vect(getX(), getY(), getZ());
	
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
		int num;
		do
		{
			std::cin >> num;
			this->setX(num);
			std::cin >> num;
			this->setY(num);
			std::cin >> num;
			this->setZ(num);
		} while (num <= 0);
	}
	
	
	return *this;
}

bool Vector::checkVectLength() {
	if (getX() == 0 && getY() == 0 && getZ() == 0)
		return true;
	else
		return false;
}
