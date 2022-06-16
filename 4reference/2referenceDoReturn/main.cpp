#include <iostream>

using namespace std;

// int &func()
// {
//     int a = 11;
//     return a;
// }

int &func2()
{
    int *p = new int(11);
    return *p;
}

int main(int argc, char *argv[])
{
    // 不能返回一个局部变量的引用
    // int &r = func();
    // cout << r << endl;

    int &r = func2();
    cout << r << endl;

    // 返回引用，函数做左值
    int &r2 = func2() = 22;
    cout << r2 << endl;

    return 0;
}