#include <iostream>

using namespace std;

class A
{
public:
    int m_a;
    void func()
    {
        cout << this->m_a << endl;
    }
};

// D中会继承到多个func 和 m_a 需要使用虚继承
// B 从而变成了虚基类
// 数据共享
class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};

int main(int argc, char *argv[])
{
    D d;
    d.m_a = 11;
    d.B::m_a = 22;
    d.C::m_a = 33;

    cout << d.m_a << endl;
    cout << d.B::m_a << endl;
    cout << d.C::m_a << endl;
    d.func();

    return 0;
}