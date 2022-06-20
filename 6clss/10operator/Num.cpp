#include "Num.h"
#include <iostream>
#include <string.h>
#include <string>

Num::Num()
{
    this->m_num = 0;
    this->m_size = 11;
    this->m_p = new char[this->m_size];
    memset(this->m_p, 0, this->m_size);
}
Num::Num(int num, int size)
{
    this->m_num = num;
    this->m_size = size;
    this->m_p = new char[this->m_size];
    memset(this->m_p, 0, this->m_size);
}

Num::Num(const Num &n)
{
    this->m_num = n.m_num;
    this->m_size = n.m_size;
    this->m_p = new char[n.m_size];
    for (int i = 0; i < this->m_size; i++)
    {
        this->m_p[i] = n.m_p[i];
    }
}

Num Num::operator+(Num &n)
{
    Num temp;
    temp.m_num = this->m_num + n.m_num;
    return temp;
}

// 运算符重载也可以进行函数重载
Num Num::operator+(int num)
{
    Num temp;
    temp.m_num = this->m_num + num;
    return temp;
}

Num Num::operator-(Num &n)
{
    Num temp;
    temp.m_num = this->m_num - n.m_num;
    return temp;
}

Num Num::operator*(Num &n)
{
    Num temp;
    temp.m_num = this->m_num * n.m_num;
    return temp;
}

Num Num::operator/(Num &n)
{
    Num temp;
    temp.m_num = this->m_num / n.m_num;
    return temp;
}

Num::~Num()
{
    if (this->m_p != nullptr)
    {
        delete[] this->m_p;
        this->m_p = nullptr;
    }
}

void Num::display()
{
    std::cout << this->m_num << std::endl;
    std::cout << this->m_p << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Num &n)
{
    out << n.m_num << " " << n.m_p;
    return out;
}

std::istream &operator>>(std::istream &in, Num &n)
{
    in >> n.m_num >> n.m_p;
    return in;
}

Num &Num::operator++() // 前置++
{
    this->m_num++;
    return *this;
}

Num Num::operator++(int) // 后置++
{
    Num temp(*this);
    this->m_num++;
    return temp;
}

Num &Num::operator=(Num &n)
{
    // 释放原空间内容
    if (this->m_p != nullptr)
    {
        delete[] this->m_p;
        this->m_p = nullptr;
    }

    this->m_num = n.m_num;
    this->m_size = n.m_size;
    this->m_p = new char[n.m_size];
    strcpy(this->m_p, n.m_p);

    return *this;
}

char &Num::operator[](int index)
{
    return this->m_p[index];
}

// 其实这东西关系多了用起来并不方便， 还不如返回一个int 已正负0来判断
bool Num::operator==(Num &n)
{
    if (this->m_num == n.m_num)
    {
        return true;
    }
    return false;
}

void Num::operator()(std::string str)
{
    std::cout << str << std::endl;
}