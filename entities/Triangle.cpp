#include "Triangle.h"
#include "Vector.h"
#include "EqualPointsException.h"
#include <vector>

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

        this->p1 = p1;
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

double Triangle::findArea()
{
    return crossProductPoints(p1, p2, p3) / 2;
}

double Triangle::findPerimeter() const
{
    Vector p1p2(p1, p2);
    Vector p1p3(p1, p3);
    Vector p2p3(p2, p3);
    return p1p2.vectorLength() + p1p3.vectorLength() + p2p3.vectorLength();
}

Point Triangle::findCentroid() const
{
    return Point((p1.getX() + p2.getX() + p3.getX()) / 3, (p1.getY() + p2.getY() + p3.getY()) / 3, (p1.getZ() + p2.getZ() + p3.getZ()) / 3);
}

bool Triangle::operator<(Point &other)
{
    return pointLiesInTriangle(other, "");
}

bool Triangle::operator>(Point &other)
{
    return !pointLiesInTriangle(other, "");
}

bool Triangle::operator==(Point &other)
{
    return pointLiesInTriangle(other, "edge");
}

bool Triangle::pointLiesInTriangle(Point &point, string condition = "inside")
{
    double area = findArea();
    double alpha = crossProductPoints(point, p2, p3) / (2 * area);
    double beta = crossProductPoints(point, p3, p1) / (2 * area);
    double gama = 1 - alpha - beta;

    return condition == "inside" ? (alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1) && (gama >= 0 && gama <= 1) && (alpha + beta + gama == 1) : (alpha >= 0 && alpha <= 1) && (beta >= 0 && beta <= 1) && (gama >= 0 && gama <= 1) && (alpha + beta + gama == 1) && (alpha == 0 || beta == 0 || gama == 0);
}

double Triangle::crossProductPoints(Point &p1, Point &p2, Point &p3)
{
    vector<double> p1p2_vec;
    p1p2_vec.push_back(p2.getX() - p1.getX());
    p1p2_vec.push_back(p2.getY() - p1.getY());
    p1p2_vec.push_back(p2.getZ() - p1.getZ());

    vector<double> p2p3_vec;
    p2p3_vec.push_back(p3.getX() - p2.getX());
    p2p3_vec.push_back(p3.getY() - p2.getY());
    p2p3_vec.push_back(p3.getZ() - p2.getZ());

    p1p2_vec.push_back(p1p2_vec.at(0));
    p1p2_vec.push_back(p1p2_vec.at(1));
    p2p3_vec.push_back(p2p3_vec.at(0));
    p2p3_vec.push_back(p2p3_vec.at(1));

    vector<double> cross_product;
    for (int i = 1; i < 4; i++)
    {
        cross_product.push_back(p1p2_vec.at(i) * p2p3_vec.at(i + 1) - p1p2_vec.at(i + 1) * p2p3_vec.at(i));
    }

    return sqrt(pow(cross_product.at(0), 2) + pow(cross_product.at(1), 2) + pow(cross_product.at(2), 2));
}

std::ostream &Triangle::ins(std::ostream &out) const
{
    out << "Triangle(Point1): " << endl
        << p1 << "Triangle(Point2): " << endl
        << p2 << "Triangle(Point3): " << endl
        << p3;
    return out;
}
std::istream &Triangle::ext(std::istream &in)
{
    in >> p1;
    in >> p2;
    in >> p3;

    return in;
}