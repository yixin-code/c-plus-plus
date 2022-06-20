#pragma once
#include <iostream>

class MyString
{
    friend std::ostream &operator<<(std::ostream &out, MyString &ms);
    friend std::istream &operator>>(std::istream &in, MyString &ms);

private:
    char *m_str;
    int m_size;

public:
    MyString();
    MyString(const char *str);
    MyString(const MyString &ms);
    MyString operator=(const MyString &ms);
    ~MyString();
};