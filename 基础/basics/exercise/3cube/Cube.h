#pragma once

class Cube
{
private:
    double m_length;
    double m_with;
    double m_height;

public:
    Cube(/* args */);
    Cube(double length, double with, double height);
    double area() const;
    double volume() const;
    bool operator==(const Cube &other);
    double getLength() const;
    double getWith() const;
    double getHeight() const;
};

bool compare(const Cube &c, const Cube &c2);