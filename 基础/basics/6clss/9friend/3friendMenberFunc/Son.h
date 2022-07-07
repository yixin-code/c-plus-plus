#pragma once
// #include "Parent.h"

class Parent; // 前置声明
class Son
{
public:
    Son();
    void func();
    void func2();
    //void func3(Parent &p);

private:
    Parent *p;
};
