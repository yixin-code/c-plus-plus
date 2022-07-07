#include <iostream>

using namespace std;

// 参数的个数， 顺序， 类型不同都可以构成重载 
// 参数为引用时const 也可构成重载
// 返回值不同 不能构成重载
void func(int &a)
{
    cout << a << endl;
}

void func(const int &a)
{
    cout << a << endl;
}

void func(double a)
{
    cout << a << endl;
}

void func(int a, double b)
{
    cout << a << " " << b << endl;
}

void func(double a, int b)
{
    cout << a << " " << b << endl;
}

// int func(int a)
// {
//     cout << a << endl;
//     return a;
// }

int main(int argc, char *argv[])
{
    func(11, 11.11);

    return 0;
}