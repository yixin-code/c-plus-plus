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

class B : private A // 私有继承
{
    // private:
    //     int m_a; // 不可访问
    //     int m_c;
    //     int m_b; 
public:
    void func()
    {
        // 私有成员， 外部不可访问
        this->m_b;
        this->m_c;
    }
};

class C : protected A
{
    // protected:
    //     int m_a; // 不可访问
    //     int m_c;
    //     int m_b;
public:
    
};

class B : private A // 私有继承
{
    // private:
    //     int m_a; // 不可访问
    //     int m_c;
    //     int m_b;
public:
    void func()
    {
        // 私有成员， 外部不可访问
        this->m_b;
        this->m_c;
    }
};

class C : protected A
{
    // protected:
    //     int m_a; // 不可访问
    //     int m_c;
    //     int m_b;
public:
    void func()
    {
        // 保护成员， 外部不可访问, 可以继承给子类
        this->m_b;
        this->m_c;
    }
};

class D : public A
{
//     int m_a; // 不能继承

// protected:
//     int m_b;

// public:
//     int m_c;
public:
    void func()
    {
        this->m_b;
        this->m_c;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}