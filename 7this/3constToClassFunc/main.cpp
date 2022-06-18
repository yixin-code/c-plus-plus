#include <iostream>

using namespace std;

class A
{
private:
    int m_a;
    mutable int m_b; // mubtable 可以让被const限定的成员函数可以修改此变量

public:
    A(/* args */) { this->m_a = 0; this->m_b = 0; }
    void display() // this相当于 A * const this 不可以修改指针指向
    {
        this->m_a = 11;
    }
    void display2() const // this相当于const A * const this 指向和值都不可以修改
    {
        // this->m_a = 11; error
        this->m_b = 11;
    }
};

int main(int argc, char *argv[])
{
    // 常对象
    const A a;
    // a.display() // error 常对象只能调用常函数
    a.display2();

    return 0;
}