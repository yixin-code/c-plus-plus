// 设计一个学生类， 属性有姓名和学号
// 可以赋值
// 能显示学生信息

#include <iostream>
#include "Student.h"

using namespace std;

int main(int argc, char *argv[])
{
    Student s;
    s.setName("小明");
    s.setNumber(111111);

    s.display();

    return 0;
}