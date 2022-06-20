#include <iostream>

using namespace std;

class A
{
public:
    A(int a) { this->m_a = a; cout << "parent" << endl; }
    ~A() { cout << "parent destructor" << endl; }
    void func()
    {
        cout << "parent" << endl;
    }

// private:
    int m_a;
};

class B : public A
{
public:
    // 继承不会继承构造 析构 拷贝构造
    // 会继承赋值运算符， 但是由于默认提供会被重载
    // 需要先构造父类
    B(int a, int a2) : A(a) { this->m_a = a2; cout << "son" << endl; }
    ~B() { cout << "son destructor" << endl; }
    void func()
    {
        cout << "son" << endl;
    }

// private:
    int m_a;
};

int main(int argc, char *argv[])
{
    B b(1, 11);
    
    // 同名成员处理
    cout << b.m_a << endl;
    cout << b.A::m_a << endl;

    b.func();
    b.A::func();

    return 0;
}