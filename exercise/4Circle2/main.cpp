// 设计一个圆类 和 点 类
// 计算点和圆的关系
// 圆心坐标x,y 点坐标x2,y2
// (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y) == r * r(圆上) > r * r(圆外) < r * r(圆内)
#include <iostream>
#include "Circle.h"

using namespace std;

int main(int argc, char *argv[])
{
    Circle c(3, 3, 11);
    Point p(11, 11);
    Point p2(1, 1);
    Point p3(3, 3);

    c.pointsAndCircle(p);
    c.pointsAndCircle(p2);
    c.pointsAndCircle(p3);

    return 0;
}