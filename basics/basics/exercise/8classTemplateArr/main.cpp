#include "MyArr.hpp"
#include <iostream>
#include <string>

class Person
{
    friend void display(MyArr<Person> &p);

private:
    int m_num;
    std::string m_name;

public:
    Person(){}
    Person(int num, std::string name)
    {
        this->m_name = name;
        this->m_num = num;
    }
};

void display(MyArr<int> &arr)
{
    for (int i = 0; i < arr.getSize(); ++i)
    {
        std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
}

void display(MyArr<Person> &arrP)
{
    for (int i = 0; i < arrP.getSize(); ++i)
    {
        std::cout << arrP[i].m_name << " " << arrP[i].m_num << std::endl;
    }
}

int main()
{
    MyArr<int> ma;
    ma.back_push(1);
    ma.back_push(2);
    ma.back_push(3);
    ma.back_push(4);
    display(ma);
    std::cout << "----------------------------------------" << std::endl;

    MyArr<Person> ma2;
    Person p(1, "aaa");
    Person p2(2, "ddd");
    Person p3(3, "ccc");
    ma2.back_push(p);
    ma2.back_push(p2);
    ma2.back_push(p3);
    display(ma2);

    return 0;
}