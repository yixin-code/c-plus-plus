#pragma once
#include "Calc.h"

class AddCalc : public Calc
{
public:
    AddCalc();
    AddCalc(int a, int b);
    virtual int result();
};