// 类模板
#include <iostream>
#include <string>

// 类模板可以有默认类型， 函数模板不能
// 类模板不能进行自动类型推导
template <class NameType, class AgeType = int>
class Person
{
private:
    NameType m_name;
    AgeType m_age;

public:
    Person(NameType name, AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    //  成员函数只有在运行的时候才会被创建
    void dispaly()
    {
        std::cout << this->m_name << " " << this->m_age << std::endl;
    }
};

// 类模板做参数
// void test(Person<std::string, int> &p)
// template <class T>
// void test(T &p)
template <class NameType, class AgeType>
void test(Person<NameType, AgeType> &p)
{
    p.dispaly();
    // 查看类型, 没用g++调用过这东西， 输出好奇怪
    std::cout << typeid(AgeType).name() << std::endl;
    std::cout << typeid(NameType).name() << std::endl;
}

int main()
{
    Person<std::string, int> p("aaa", 11);
    Person<std::string> p2("bbb", 22);
    p.dispaly();
    p2.dispaly();

    std::cout << "-------------------" << std::endl;

    test(p);
    test(p2);



    return 0;
}