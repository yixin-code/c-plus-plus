#pragma once
#include "Son.h"

class Son; // 前置声明
class Parent
{
    // 将func指定为友元函数
    friend void Son::func();
    // friend void Son::func(Parent &p);
private:
    int m_computer;
    int m_salary;
public:
    Parent();
};