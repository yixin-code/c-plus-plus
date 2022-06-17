#include <iostream>
#include "Student.h"

using namespace std;

int main(int argc, char *argv[])
{
    Student s(11, "aaa");
    Student s2(s);

    return 0;
}