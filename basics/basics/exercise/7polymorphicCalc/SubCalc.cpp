#include "SubCalc.h"

SubCalc::SubCalc() : Calc()
{

}

SubCalc::SubCalc(int a, int b) : Calc(a, b)
{

}

int SubCalc::result()
{
    return this->getNum() - this->getNum2();
}