#include "Student.h"
#include <iostream>

using namespace std;

// C++中 new delete是运算符
int main(int argc, char *argv[])
{
    Student *stu = new Student(11, "aaa");
    stu->display();
    if (stu != nullptr)
    {
        delete stu;
        stu = nullptr;
    }

    cout << "--------------------" << endl;

    Student *stus = new Student[3];
    stus[0].setAge(1);
    stus[0].setName("aaa");
    stus[1].setAge(2);
    stus[1].setName("bbb");
    stus[2].setAge(3);
    stus[2].setName("ccc");

    for (int i = 0; i < 3; ++i)
    {
        stus[i].display();
    }

    if (stus != nullptr)
    {
        delete[] stus;
        stus = nullptr;
    }

    return 0;
}