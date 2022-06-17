#include "Point.h"

Point::Point()
{
    this->m_x = 0;
    this->m_y = 0;
}

Point::Point(double x, double y)
{
    this->m_x = x;
    this->m_y = y;
}

double Point::getX() const
{
    return this->m_x;
}

double Point::getY() const
{
    return this->m_y;
}