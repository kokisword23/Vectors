#include "Triangle.h"
#include "equalpointexception.h"

Triangle::Triangle(Point p1, Point p2, Point p3)
{
    try
    {
        if (p1 == p2)
            throw EqualPointException("ERROR: Equal points (Point \"A\" and Point \"B\").");
        else if (p2 == p3)
            throw EqualPointException("ERROR: Equal points (Point \"B\" and Point \"C\").");
        else if (p1 == p3)
            throw EqualPointException("ERROR: Equal points (Point \"A\" and Point \"C\").");
        else if (p1 == p2 && p2 == p3)
            throw EqualPointException("ERROR: Equal points (Point \"A\", Point \"B\" and Point \"C\").");

        this->p1 = Point(p1.getX(), p1.getY(), p1.getZ());
        this->p2 = p2;
        this->p3 = p3;
        this->side1 = sqrt(pow((p2.getX() - p1.getX()), 2) + pow((p2.getY() - p1.getY()), 2));
        this->side2 = sqrt(pow((p3.getX() - p2.getX()), 2) + pow((p3.getY() - p2.getY()), 2));
        this->side3 = sqrt(pow((p3.getX() - p1.getX()), 2) + pow((p3.getY() - p1.getY()), 2));
    }
    catch (EqualPointException &e)
    {
        cout << e.what() << endl;
    }
}

void Triangle::clasifyTriangle() const
{

    int a = 0, b = 0, c = 0;
    c = side1;
    a = side2;
    b = side3;
    if (side2 > c)
    {
        c = side2;
        a = side1;
        b = side3;
    }
    if (side3 > c)
    {
        c = side3;
        a = side1;
        b = side2;
    }

    if ((side1 == side2 && side3 != side1) || (side2 == side3 && side1 != side2) || (side1 == side3 && side2 != side1))
    {
        cout << "ravnobedren" << endl;
        (pow(a, 2) + pow(b, 2) == pow(c, 2)) ? cout << "pravougulen" << endl : (pow(a, 2) + pow(b, 2) < pow(c, 2)) ? cout << "tupougulen" << endl : (pow(a, 2) + pow(b, 2) > pow(c, 2)) ? cout << "ostrougulen" << endl : cout << "neopredelen" << endl;
    }
    else if (side1 == side2 == side3)
    {
        cout << "ravnostranen" << endl
             << "ostrougulen";
    }
}

double Triangle::findArea() const
{
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::findPerimeter() const
{
    return side1 + side2 + side3;
}

Point Triangle::findCentroid() const
{
    return Point((p1.getX() + p2.getX() + p3.getX()) / 3, (p1.getY() + p2.getY() + p3.getY()) / 3, (p1.getZ() + p2.getZ() + p3.getZ()) / 3);
}

bool Triangle::operator<(Point &other)
{

    Triangle t1 = Triangle(p1, p2, other);
    Triangle t2 = Triangle(p1, p3, other);
    Triangle t3 = Triangle(p2, other, p3);

    return findArea() == t1.findArea() + t2.findArea() + t3.findArea();
}

bool Triangle::operator>(Point &other)
{
    Triangle t1 = Triangle(p1, p2, other);
    Triangle t2 = Triangle(p1, p3, other);
    Triangle t3 = Triangle(p2, other, p3);

    return findArea() != t1.findArea() + t2.findArea() + t3.findArea();
}
