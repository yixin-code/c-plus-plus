#pragma once
#include "Num.h"

class SmartPoint
{
private:
    Num *m_n;
public:
    SmartPoint(Num *n);
    ~SmartPoint();
    Num *operator->();
    Num &operator*();
};