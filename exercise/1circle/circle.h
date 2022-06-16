#pragma once

const double PI = 3.14;

class Circle
{
private:
    double m_radius;

public:
    Circle();
    Circle(double radius);
    double perimeter();
    void setRadius(double radius);
    double getRadius() const;
};
