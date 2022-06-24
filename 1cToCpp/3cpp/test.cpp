// 算数运算只有 int long float double 其他都会转换成这些类型
#include <iostream>

using namespace std;

struct A // cpp中可以在结构体中加入函数
{
    int m_a;
    void func();
};

enum Num
{
    zero,
    one,
    two,
    three
};

// 全局区的const 在C中也是不可修改的
const int g_a = 11;

void typeEnhance()
{
    int *p = (int *)malloc(11); // 在C++ 中必须强转

    // const int a = 11; // C++中的const在符号表中, 并不会分配内存
    // int *p2 = &a; // 这个不同编译器不同？ 在VS中p2会指向临时开辟的空间
    // *p2 = 111;
    // cout << "a = " << a << endl;

    int arr[2][3];
    // int *p = arr;
    int(*p3)[] = arr; // arr是首元素地址， arr的首元素是int[3] p3 为指向int[3]的指针

    // bool 类型
    cout << "sizeof(bool) = " << sizeof(bool) << endl;

    // enum Num num = 1; // C++ 中枚举只能赋值选项 
    enum Num num = one;

    int a, b, c = 11;
    (a = b) = c; // c++中返回的是引用
}

// long long 在任何系统下都是32位
void func(long long a)
{
    cout << "a = " << a << endl;
}

void func(int *a)
{
    cout << "aaaaaaaaa = " << a << endl;
}

int main()
{
    // func(NULL); // 0 调用func(long long a)
    func(nullptr); // 空指针类型 调用func(int *a)

    return 0;
}