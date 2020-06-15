#include "Segment.h"


Segment::Segment() 
{
    this->startPoint.setX(0);
    this->startPoint.setY(0);
    this->startPoint.setZ(0);
    this->endPoint.setX(0);
    this->endPoint.setY(0);
    this->endPoint.setZ(0);
}
Segment::Segment(Point& p1, Point& p2)
{
    this->startPoint.setX(p1.getX());
    this->startPoint.setY(p1.getY());
    this->startPoint.setZ(p1.getZ());
    this->endPoint.setX(p2.getX());
    this->endPoint.setY(p2.getY());
    this->endPoint.setZ(p2.getZ());
    Line l(this->startPoint, this->endPoint);
}


Segment::Segment(const Segment& rhs)
{
    this->startPoint.getX() = rhs.startPoint.getX();
    this->startPoint.getY() = rhs.startPoint.getY();
    this->startPoint.getZ() = rhs.startPoint.getZ();
    this->endPoint.getX() = rhs.endPoint.getX();
    this->endPoint.getY() = rhs.endPoint.getY();
    this->endPoint.getZ() = rhs.endPoint.getZ();
    Line l(this->startPoint, this->endPoint);
}

Segment& Segment:: operator=(const Segment& rhs)
{
    if (this != &rhs)
    {
        this->startPoint.getX() = rhs.startPoint.getX();
        this->startPoint.getY() = rhs.startPoint.getY();
        this->startPoint.getZ() = rhs.startPoint.getZ();
        this->endPoint.getX() = rhs.endPoint.getX();
        this->endPoint.getY() = rhs.endPoint.getY();
        this->endPoint.getZ() = rhs.endPoint.getZ();
        Line l(this->start_point, this->end_point);
    }
    return this;
}

Segment:: ~Segment() {}

float Segment::findSegmentLength()
{
    Vector temp;
    temp.setX(this->endPoint.getX() - this->startPoint.getX();
    temp.setY(this->endPoint.getY() - this->startPoint.getY();
    temp.setZ(this->endPoint.getZ() - this->startPoint.getZ();
    return temp.vectorLength();    
}

Point Segment::findSegmentMid()
{
    Point Mid
    Mid.setX(this->startPoint.getX() + this->endPoint.getX() / 2);
    Mid.setY(this->startPoint.getY() + this->endPoint.getY() / 2);
    Mid.setZ(this->startPoint.getZ() + this->endPoint.getZ() / 2);
    return Mid;
}

bool Segment:: operator==(Point& p)
{
    float t1,t2,t3;
    float x = p.getX();
    float y = p.getY();
    float z = p.getZ();
    t1 = (p.getX() - this->startPoint.getX()) / (this->endPoint.getX() - this->startPoint.getX());
    t2 = (p.getY() - this->startPoint.getY()) / (this->endPoint.getY() - this->startPoint.getY());
    t3 = (p.getZ() - this->startPoint.getZ()) / (this->endPoint.getZ() - this->startPoint.getZ());

    if (t1 == t2 && t2 == t3)return true;
    return false;
}