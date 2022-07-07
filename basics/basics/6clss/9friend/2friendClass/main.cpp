// 友元类
#include <iostream>
#include "Parent.h"
#include "Son.h"

using namespace std;

int main(int argc, char *argv[])
{
    Parent p;
    Son s;
    s.func(p);

    return 0;
}