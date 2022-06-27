#include "Student.h"
#include <iostream>

    Student::Student()
    {
        this->m_name = "NONE";
        this->m_number = 0;
    }

    Student::Student(std::string name, int number)
    {
        this->m_name = name;
        this->m_number = number;
    }

    void Student::setName(std::string  name)
    {
         this->m_name = name;
    }

    void Student::setNumber(int number)
    {
        this->m_number = number;
    }

    void Student::display() const
    {
        std::cout << this->m_name<< " " << this->m_number << std::endl;
    }