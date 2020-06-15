#include "Line.h"
#include <cstring>

class Segment : public Line {

protected:
    Point startPoint;
    Point endPoint;
public:
    Segment(Point a, Point b);
    Segment(Point a, Point b, Point &p1, Point &p2);
    ~Segment();
    Segment(Point a, Point b, const Segment &rhs);
    Segment * operator=(const Segment& rhs);

    float findSegmentLength();
    Point findSegmentMid();
    bool operator==(Point&);

    virtual std::ostream& ins(std::ostream&) const ;
    virtual std::istream& ext(std::istream&);
};
