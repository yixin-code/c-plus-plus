#include <iostream>

using namespace std;

class A
{
public:
    A(int a)
    {
        this->m_a = a;
        cout << "A" << endl;
    }
    int m_a;
};

class B
{
public:
    B(int a)
    {
        this->m_a = a;
        cout << "B" << endl;
    }
    int m_a;
};

// 构造顺序和继承的顺序相关
class C : public A, public B
{
public:
    C(int a, int a2, int a3) : A(a2), B(a3)
    {
        this->m_a = a;
        cout << "C" << endl;
    }
    int m_a;
};

int main(int argc, char *argv[])
{
    C c(3, 1, 2);
    cout << c.m_a << endl;
    cout << c.A::m_a << endl;
    cout << c.B::m_a << endl;

    return 0;
}