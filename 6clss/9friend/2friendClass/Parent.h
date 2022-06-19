#pragma once

class Parent
{
    // 将son指定为友元类， son可以访问Parent的所有私有成员
    friend class Son;
private:
    int m_computer;
    int m_salary;
public:
    Parent();
};