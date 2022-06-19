#include "Son.h"
#include "Parent.h"
#include <iostream>

Son::Son()
{
    this->p = new Parent;
}

void Son::func()
{
    std::cout << this->p->m_computer << std::endl;
    std::cout << this->p->m_salary << std::endl;
}

void Son::func2()
{
    // 不可访问
    // std::cout << this->p->m_computer << std::endl;
    // std::cout << this->p->m_salary << std::endl;
}

// void Son::func3(Parent &p)
// {
//     std::cout << 
// }