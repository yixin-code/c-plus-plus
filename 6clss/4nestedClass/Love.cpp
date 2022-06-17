#include "Love.h"
#include <iostream>

Love::Love()
{
    std::cout << "Love constructor" << std::endl;
}

Love::Love(std::string name)
{
    std::cout << "Love argument constructor" << std::endl;
    this->m_name = name;
}

std::string Love::getName() const
{
    return this->m_name;
}

Love::~Love()
{
    std::cout << "Love destructor" << std::endl;
}