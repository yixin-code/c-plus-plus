#pragma once
#define  _CRT_SECURE_NO_WARNINGS

class Student
{
private:
    int m_age;
    char *m_name;
public:
    Student();
    Student(int age,const char *name);
    Student(const Student &s);
    ~Student();
};