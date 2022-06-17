#pragma once

class Point
{
private:
    double m_x;
    double m_y;
public:
    Point();
    Point(double x, double y);
    double getX() const;
    double getY() const;
};