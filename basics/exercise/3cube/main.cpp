// 设计立方体，求出面积 体积
// 用全局和成员函数判断两个立方体是否相等
#include <iostream>
#include "Cube.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cube c(1.1, 2.2, 3.3);
    Cube c2(1.1, 2.2, 3.3);
    Cube c3(1.2, 2.2, 3.2);

    cout << "c area = " << c.area() << endl;
    cout << "c volume = " << c.volume() << endl;

    cout << "operator" << endl;
    if (c == c2)
    {
        cout << "c == c2" << endl;
    }
    else
    {
        cout << "c != c2" << endl;
    }

    if (c == c3)
    {
        cout << "c == c3" << endl;
    }
    else
    {
        cout << "c != c3" << endl;
    }

    cout << "compare" << endl;
    if (compare(c, c2))
    {
        cout << "c == c2" << endl;
    }
    else
    {
        cout << "c != c2" << endl;
    }

    if (compare(c, c3))
    {
        cout << "c == c3" << endl;
    }
    else
    {
        cout << "c != c3" << endl;
    }

    return 0;
}