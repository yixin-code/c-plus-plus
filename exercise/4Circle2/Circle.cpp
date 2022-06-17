#include "Circle.h"
#include <iostream>

Circle::Circle(/* args */) : p(0, 0)
{
    this->m_radius = 0;
}

Circle::Circle(double x, double y, double radius) : p(x, y)
{
    this->m_radius = radius;
}

// 等于0 相等， 大于0圆外， 小于0圆内
void Circle::pointsAndCircle(const Point &p) const
{
    int temp = ((p.getX() - this->p.getX()) * (p.getX() - this->p.getX()) +
        (p.getY() - this->p.getY()) * (p.getY() - this->p.getY())) - 
        this->m_radius * this->m_radius;
       
    if (temp == 0)
    {
        std::cout << "点在圆上" << std::endl;
    }
    else if (temp > 0)
    {
        std::cout << "点在圆外" << std::endl;
    }
    else
    {
        std::cout << "点在圆内" << std::endl;
    }
}
