#include "circle.h"

Circle::Circle()
{
    this->m_radius = 0.0;
}

Circle::Circle(double radius)
{
    this->m_radius = radius;
}

double Circle::perimeter()
{
    return 2 * PI * this->m_radius;
}

void Circle::setRadius(double radius)
{
    this->m_radius = radius;
}

double Circle::getRadius() const
{
    return this->m_radius;
}