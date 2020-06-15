#include "Element.h"
#include <iostream>
#pragma once
class Point : public Element
{
public:
    Point(double x, double y, double z);

    Point();

    bool operator==(Point point);
    Point &operator=(const Point &);
    virtual std::ostream &ins(std::ostream &) const;
    virtual std::istream &ext(std::istream &);
};

std::ostream &operator<<(std::ostream &, const Point &);
std::istream &operator>>(std::istream &lhs, Point &rhs);