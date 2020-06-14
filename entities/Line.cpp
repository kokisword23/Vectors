#include "Line.h"

Line::Line(Point a, Point b) : Vector(a,b) {}

Line::Line(Point a, Vector v) : Vector(v) {}


Vector Line::lineDirection() {

	//toDo returns vector parallel to the line (this) a vector is parallel to a line if the v1 equation of the points
	//is equal to -2v2 example - v1 = ?2i + 4j + 10k, v2 = i - 2j - 5k => v1 = -2v2 - parallel

	return Vector();
}
