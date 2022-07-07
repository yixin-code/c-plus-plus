#include "Student.h"
#include <iostream>

Student::Student()
{
    std::cout << "Student constructor" << std::endl;
}

Student::Student(std::string name, std::string love_name, int id) : m_love(love_name), m_id(id)
{
    std::cout << "Student argument constructor" << std::endl;
    this->m_name = name;
}

void Student::display()
{
    std::cout << this->m_name << " " << this->m_love.getName() << " " << this->m_id.getId() << std::endl;
}

Student::~Student()
{
    std::cout << "Student destructor" << std::endl;
}