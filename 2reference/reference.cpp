#include <iostream>

using namespace std;

struct A
{
    int a;
    double b;
};

// 指针和引用大小相等, 引用必须初始化, 无法改变指向。 约等于 type * const p 常指针
void func()
{
    A a{11, 11.11};
    A &r = a;
    A *p = &a;

    // 64位
    cout << "sizeof(r) = " << sizeof(r) << endl;   // 16 是变量本身的大小
    cout << "sizeof(a) = " << sizeof(a) << endl;   // 16
    cout << "sizeof(&r) = " << sizeof(&r) << endl; // 8 可以理解成引用本身的大小
    cout << "sizeof(p) = " << sizeof(p) << endl;   // 8

    A *p2 = &r;
    cout << "&r = " << &r << endl; // 对引用取地址 就是对引用变量本身取地址
    cout << "p2 = " << p2 << endl; //
}

// 引用作函数返回值
// 不能让返回局部变量的引用
int &func2()
{
    int a = 10;
    return a;
}

// 返回引用函数可以做左值
int &func3(int *&p)
{
    p = new int(11);
    return *p; // 指针的引用
}

int main()
{
    // func();

    // int a = func2();
    // cout << a << endl; // 可以正常返回10 相当于 main::a = func::a
    // int &r = func2();
    // cout << r << endl; // 不能正常返回, 引用相当于长指针， func是局部变量执行后释放。 r无法正确的引用

    int *p = nullptr;
    func3(p) = 1111;
    cout << "*p = " << *p << endl;

    return 0;
}