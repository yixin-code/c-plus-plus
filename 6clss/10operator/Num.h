#pragma once
#include <iostream>

class Num
{
    friend std::ostream& operator<<(std::ostream &out,const Num &n);
    friend std::istream& operator>>(std::istream &in, Num &n);
private:
    int m_num;
    int m_size;
    char *m_p;
public:
    // 系统默认
    Num();
    Num(int num, int size);
    Num(const Num &n);
    Num &operator=(Num &n);
    ~Num();

    Num operator+(Num &n);
    Num operator+(int num);
    Num operator-(Num &n);
    Num operator*(Num &n);
    Num operator/(Num &n);
    Num& operator++(); // 前置++ 内置 可以++++num 所以需要返回引用
    Num operator++(int); // 后置++ 内置 不可以 num++++ 所以返回值
    char &operator[](int index);
    bool operator==(Num &n);

    // 仿函数
    void operator()(std::string str);
    void display();
};