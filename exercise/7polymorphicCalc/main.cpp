#include <iostream>
#include "Calc.h"
#include "AddCalc.h"
#include "SubCalc.h"

using namespace std;

int main(int argc, char *argv[])
{
    Calc *pc = new AddCalc;
    pc->setNum(1);
    pc->setNum2(11);
    cout << pc->result() << endl;

    Calc *pc2 = new SubCalc;
    pc2->setNum(1);
    pc2->setNum2(11);
    cout << pc2->result() << endl;

    delete pc;
    delete pc2;

    return 0;
}