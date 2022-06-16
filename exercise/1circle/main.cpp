// 设计圆类，求周长
#include <iostream>
#include "circle.h"

using namespace std;

int main(int argc, char *argv[])
{
    Circle c(11);
    cout << c.perimeter() << endl;

    Circle c2;
    c2.setRadius(22);
    cout << c2.getRadius() << endl;
    cout << c2.perimeter() << endl;

    return 0;
}