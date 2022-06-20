#include <iostream>

using namespace std;

class Parent
{
public:
    static int m_a;
    static void func()
    {
        cout << "parent" << endl;
    }
};
int Parent::m_a = 1;

// 静态成员都会被继承
class Son : public Parent
{
public:
    static int m_a;
    static void func()
    {
        cout << "son" << endl;
    }
};
int Son::m_a = 11;

int main(int argc, char *argv[])
{
    Son s;
    cout << Son::m_a << endl;
    cout << Parent::m_a << endl;
    cout << Son::Parent::m_a << endl;

    Son::func();
    Parent::func();
    Son::Parent::func();

    return 0;
}