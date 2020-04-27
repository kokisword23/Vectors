#include "Line.h"

Line::Line(Point a, Point b) : Vector(a,b) {}

Line::Line(Point a, Vector v) : Vector(v) {}
