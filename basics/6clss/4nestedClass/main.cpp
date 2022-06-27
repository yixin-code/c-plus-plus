#include <iostream>
#include "Student.h"

using namespace std;

int main(int argc, char *argv[])
{
    Student s("小明", "小兰", 1111);
    s.display();
    Student s2;
    s2.display();

    return 0;
}