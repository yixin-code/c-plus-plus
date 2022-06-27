#include "AddCalc.h"

AddCalc::AddCalc() : Calc()
{

}

AddCalc::AddCalc(int a, int b) : Calc(a, b)
{

}

int AddCalc::result()
{
    return this->getNum() + this->getNum2();
}