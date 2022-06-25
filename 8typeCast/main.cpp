#include <iostream>

using namespace std;

// 基础类型
void test()
{
    int a = 11;
    double b = 22;
    b = static_cast<double>(a);
}

// 父子间 指针或引用
class Parent
{
};
class Son : public Parent
{
};
void test2()
{
    Son s;
    Parent *p = static_cast<Parent *>(&s);
}

// dynamic_cast严格转换，失去精度, 不安全都无法转换
// 发生多态的时候可以进行父转子，因为父类对象指针或引用指向子类对象， 开辟的本身就是子类的空间大小
void test3()
{
    Son s;
    Parent &p = dynamic_cast<Parent &>(s);
}

// const_cast 常量转换， 不能对非引用或指针进行转换
void test4()
{
    int *p = nullptr;
    const int *p2 = const_cast<const int *>(p);

    // 脱常使用频率很高
    const int *p3 = nullptr;
    int *p4 = const_cast<int *>(p3);

    int num = 10;
    const int &r = const_cast<const int&>(num);
}

// reinterpret_cast 可以随意转换无安全可言， 不会使用


int main(int argc, char *argv[])
{
    test();
    test2();
    test3();
    test4();

    return 0;
}