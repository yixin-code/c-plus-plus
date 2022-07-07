#include <iostream>
#include "Printer.h"

using namespace std;

int main(int argc, char *argv[])
{
    Printer *p = Printer::getPrinter();

    p->print("aaa");
    p->print("bbb");
    p->print("ccc");

    cout << "打印 " << p->getCount() << " 次" << endl;

    return 0;
}