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
    cout << "sizeof(r) = " << sizeof(r) << endl; // 16 是变量本身的大小
    cout << "sizeof(a) = " << sizeof(a) << endl; // 16
    cout << "sizeof(&r) = " << sizeof(&r) << endl; // 8 可以理解成引用本身的大小
    cout << "sizeof(p) = " << sizeof(p) << endl; // 8

    A *p2 = &r;
    cout << "&r = " << &r << endl;  // 对引用取地址 就是对引用变量本身取地址
    cout << "p2 = " << p2 << endl; // 
}

int main()
{
    func();

    return 0;
}