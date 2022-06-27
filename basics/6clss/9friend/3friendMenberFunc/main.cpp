// 成员函数做友元函数
#include <iostream>
#include "Parent.h"
#include "Son.h"

using namespace std;

int main(int argc, char *argv[])
{
    Parent p;
    Son s;
    s.func();

    return 0;
}