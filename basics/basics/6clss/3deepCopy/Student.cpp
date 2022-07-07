#include "Student.h"
#include <string.h>

Student::Student()
{
    this->m_age = 0;
    this->m_name = nullptr;
}

Student::Student(int age,const char *name)
{
    this->m_age = age;

    this->m_name = new char[strlen(name) + 1];
    strcpy(this->m_name, name);
}

// 系统提供的拷贝构造是简单的值拷贝， 会造成m_name指向同一个空间
Student::Student(const Student &s)
{
    this->m_age = s.m_age;

    this->m_name = new char[strlen(s.m_name) + 1];
    strcpy(this->m_name, s.m_name);
}
Student::~Student()
{
    if (this->m_name != nullptr)
    {
        delete[] this->m_name;
        this->m_name =nullptr;
    }
}