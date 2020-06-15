#include "Line.h"
#include <cstring>

class Segment : public Line {

protected:
    Point startPoint;
    Point endPoint;
public:
    Segment();
    Segment(Point&, Point&);
    ~Segment();
    Segment(const Segment& rhs);
    Segment& operator=(const Segment& rhs);

    float findSegmentLength();
    Point findSegmentMid();
    bool operator==(Point&);
    
};
