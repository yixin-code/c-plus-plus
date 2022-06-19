#include "Son.h"
#include "Parent.h"
#include <iostream>

void Son::func(Parent &p)
{
    std::cout << p.m_computer << std::endl;
    std::cout << p.m_salary << std::endl;
}