#include "Element.h"

class Point : public Element {
public:
    Point(double x, double y, double z);

    Point();

    bool operator == (Point point);
};
