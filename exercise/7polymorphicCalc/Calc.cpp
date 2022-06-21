#include "Calc.h"

Calc::Calc()
{
    this->m_num = 0;
    this->m_num2 = 0;
}

Calc::Calc(int num, int num2)
{
    this->m_num = num;
    this->m_num2 = num2;
}

void Calc::setNum(int num)
{
    this->m_num = num;
}

void Calc::setNum2(int num)
{
    this->m_num2 = num;
}

int Calc::result()
{
    return 0;
}

int Calc::getNum() const
{
    return this->m_num;
}

int Calc::getNum2() const
{
    return this->m_num2;
}