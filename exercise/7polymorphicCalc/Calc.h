#pragma once

class Calc
{
private:
    int m_num;
    int m_num2;

public:
    Calc();
    Calc(int num, int num2);
    void setNum(int num);
    void setNum2(int num);
    int getNum() const;
    int getNum2() const;
    // virtual int result() = 0; // 纯虚函数子类必须重写，父类无需实现，有纯虚函数的类无法实例化对象
    virtual int result();
};