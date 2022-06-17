#pragma once
#include <iostream>

class A
{
public:
    // 与类名相同，无返回值， 可以发生重载， 系统默认调用， 如果不提供系统会提供默认什么都不做的无参构造函数
    A() { std::cout << "constructor" << std::endl; }
    // 有参构造
    A(int a)
    {
        m_a = a;
        std::cout << "parameter" << std::endl;
    }
    // 拷贝构造
    A(const A &other) {
        std::cout << "copy constructor" << std::endl;
    }
    // A(const A &other)
    // {
    //     m_a = other.m_a;
    //     std::cout << "copy constructor" << std::endl;
    // };
    // ~类名， 无返回值， 无参数， 不能发生重载， 如果不提供系统会提供默认什么都不做的无参析构函数
    ~A() { std::cout << "destructor" << std::endl; }

private:
    int m_a;
};