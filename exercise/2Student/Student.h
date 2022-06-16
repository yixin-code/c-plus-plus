#pragma once
#include <string>

class Student
{
private:
    std::string m_name;
    int m_number;

public:
    Student();
    Student(std::string name, int number);
    void setName(std::string  name);
    void setNumber(int number);
    void display() const;
};
