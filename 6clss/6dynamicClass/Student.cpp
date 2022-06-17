#include "Student.h"
#include <iostream>

Student::Student()
{
    this->m_age = 0;
    this->m_name = "none";
}

Student::Student(int age, std::string name)
{
    this->m_age = age;
    this->m_name = name;
}

void Student::setAge(int age)
{
    this->m_age = age;
}

void Student::setName(std::string name)
{
    this->m_name = name;
}

std::string Student::getName() const
{
    return this->m_name;
}

int Student::getAge() const
{
    return this->m_age;
}

void Student::display() const
{
    std::cout << this->m_name << " " << this->m_age << std::endl;
}