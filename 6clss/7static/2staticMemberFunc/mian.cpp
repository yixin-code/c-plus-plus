// 静态成员函数不能调用普通成员变量， 没有this指针
// 静态属于整个类， 并不属于某一个对象
//
#include <iostream>

using namespace std;

class A
{
public:
    static int s_num;
    static void func();
    int m_a;
};

int A::s_num = 11;

void A::func()
{
    cout << "static void func();" << endl;
    cout << A::s_num << endl;
    // m_a = 11; 不能调用 没有this指针 不属于对象
}

int main(int argc, char *argv[])
{
    A a;

    a.func();
    A::func();

    return 0;
}