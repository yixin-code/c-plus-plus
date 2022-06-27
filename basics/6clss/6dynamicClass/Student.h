#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Student
{
private:
    int m_age;
    std::string m_name;

public:
    Student();
    Student(int age, std::string name);
    void setAge(int age);
    void setName(std::string name);
    std::string getName() const;
    int getAge() const;
    void display() const;
};