#include <iostream>

using namespace std;

enum Num
{
    zero,
    one,
    two,
    three
};

void typeEnhance()
{
    int *p = (int *)malloc(11); // 在C++ 中必须强转

    // const int a = 11;
    // int *p2 = &a; // 这个我记得在VS上是可以的， p2会是一个临时空间地址
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
    func(NULL); // 0 调用func(long long a)
    func(nullptr); // 空指针类型 调用func(int *a)

    return 0;
}