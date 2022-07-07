#include "MyString.h"
#include <iostream>
#include <string.h>

MyString::MyString()
{
    std::cout << "默认构造函数" << std::endl;
    this->m_str = nullptr;
    this->m_size = 0;
}

MyString::MyString(const char *str)
{
    std::cout << "有参构造函数" << std::endl;
    this->m_str = new char[strlen(str) + 1];
    this->m_size = strlen(str);
    strcpy(this->m_str, str);
}

MyString::MyString(const MyString &ms)
{
    std::cout << "拷贝构造" << std::endl;
    this->m_size = ms.m_size;
    this->m_str = new char[strlen(ms.m_str) + 1];
    strcpy(this->m_str, ms.m_str);
}

MyString MyString::operator=(const MyString &ms)
{
    std::cout << "赋值运算符" << std::endl;
    if (this->m_str != nullptr)
    {
        delete[] this->m_str;
        this->m_str = nullptr;
    }

    this->m_size = ms.m_size;
    this->m_str = new char[strlen(ms.m_str) + 1];
    strcpy(this->m_str, ms.m_str);
    return *this;
}

MyString::~MyString()
{
    std::cout << "析构函数" << std::endl;
    if (this->m_str != nullptr)
    {
        delete[] this->m_str;
        this->m_str = nullptr;
    }
}

std::ostream &operator<<(std::ostream &out, MyString &ms)
{
    out << ms.m_str;
    return out;
}

std::istream &operator>>(std::istream &in, MyString &ms)
{
    if (ms.m_str != nullptr)
    {
        delete[] ms.m_str;
        ms.m_str = nullptr;
    }

    char buf[1024];
    std::cin >> buf;

    ms.m_str = new char[strlen(buf) + 1];
    strcpy(ms.m_str, buf);
    ms.m_size = strlen(buf);

    return in;
}

MyString MyString::operator+(const char *str)
{
    int tempSize = this->m_size + strlen(str);
    // char *temp = new char[tempSize + 1];
    this->m_str = (char *)realloc(this->m_str, tempSize + 1);
    strcat(this->m_str, str);
    this->m_size = tempSize;

    return *this;
}

MyString MyString::operator+(const MyString &ms)
{
    int tempSize = this->m_size + strlen(ms.m_str);
    this->m_str = (char *)realloc(this->m_str, tempSize + 1);
    strcat(this->m_str, ms.m_str);
    this->m_size = tempSize;

    return *this;
}

int MyString::getSize() const
{
    return this->m_size;
}

bool MyString::operator==(const char *str)
{
    if (strcmp(this->m_str, str) == 0)
    {
        return true;
    }
    return false;
}

bool MyString::operator==(const MyString &ms)
{
    if (strcmp(this->m_str, m_str) == 0)
    {
        return true;
    }
    return false;
}