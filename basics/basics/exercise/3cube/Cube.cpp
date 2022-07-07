#include "Cube.h"

Cube::Cube(/* args */)
{
    this->m_height = 0;
    this->m_length = 0;
    this->m_with = 0;
}

Cube::Cube(double length, double with, double height)
{
    this->m_height = height;
    this->m_length = length;
    this->m_with = with;
}

double Cube::area() const
{
    return 2 * this->m_height * this->m_length +
           2 * this->m_height * this->m_with + 2 * this->m_length * this->m_with;
}

double Cube::volume() const
{
    return this->m_height * this->m_length * this->m_with;
}

bool Cube::operator==(const Cube &other)
{
    if (this->m_height == other.m_height && this->m_length == other.m_length && this->m_with == other.m_with)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Cube::getLength() const
{
    return this->m_length;
}

double Cube::getWith() const
{
    return this->m_with;
}

double Cube::getHeight() const
{
    return this->m_height;
}

bool compare(const Cube &c,const Cube &c2)
{
    if (c.getHeight() == c2.getHeight() && c.getLength() == c2.getLength() && c.getWith() == c2.getWith())
    {
        return true;
    }
    else
    {
        return false;
    }
}