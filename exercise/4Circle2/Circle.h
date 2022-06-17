#pragma once
#include "Point.h"

class Circle
{
private:
    double m_radius;
    Point p;
public:
    Circle(/* args */);
    Circle(double x, double y, double radius);
    void pointsAndCircle(const Point &p) const;
};
