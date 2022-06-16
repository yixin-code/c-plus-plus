#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // 引用必须初始化, 初始化后不能修改

    // 数组引用
    int arr[3] = {1, 2, 3};
    int (&r)[3] = arr;
    // typedef int (ARR)[3]; // 也可以这样
    // ARR &r = arr;
    for (int i = 0; i < 3; i++)
    {
        cout << r[i] << endl;
    }
 
    int a = 11;

    int &r2 = a; // 相当于int *const r2 = a; 不可以改变指向1
    r2 = 20; // 相当于*r2 = 20

    // 指针的引用
    int *p = &a;
    int *&r3 = p;
    cout << r3 << endl; // 地址
    cout << *r3 << endl; // 20 值

    // const和引用， 函数传参可能会传入常量时会用到
    const int b = 11;
    // int &r4 = 11; error
    // int &r4 = b; error
    const int &r4 = b; // 相当于 int temp = 11; const int &r3 = temp;

    return 0;
}