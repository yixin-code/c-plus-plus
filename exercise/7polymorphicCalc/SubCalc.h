
#pragma once
#include "Calc.h"

class SubCalc: public Calc
{
public:
    SubCalc();
    SubCalc(int a, int b);
    virtual int result();
};