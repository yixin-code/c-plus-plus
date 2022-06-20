#pragma pack(1)
#include <iostream>

using namespace std;

class A
{
private:
    int m_a; // 不能继承给子类

protected:
    int m_b; // 可以继承给子类

public:
    int m_c; // 可以继承给子类
};

class B : public A // 会将A类中的全部成员变量都继承, 只是私有成员不显示
{
public:
    int m_a;
};

int main(int argc, char *argv[])
{
    cout << sizeof(B) << endl; // 16

    return 0;
}