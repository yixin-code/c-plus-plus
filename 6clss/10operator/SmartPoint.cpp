#include "SmartPoint.h"

SmartPoint::SmartPoint(Num *n)
{
    this->m_n = n;
}

SmartPoint::~SmartPoint()
{
    if (this->m_n != nullptr)
    {
        delete this->m_n;
        this->m_n = nullptr;
    }
}

Num *SmartPoint::operator->()
{
    return this->m_n;
}

Num &SmartPoint::operator*()
{
    return *this->m_n;
}