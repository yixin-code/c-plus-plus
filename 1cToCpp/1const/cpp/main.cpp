#include <iostream>

using namespace std;

struct A
{
    int a;
    int b;
};


int main(int argc, char *argv[])
{
    // 在C++中const是内部链接，无法访问外部的const
    extern const int NUM;
    cout << NUM << endl;

    int a = 11;
    const int c_a = a; // 会分配内存

    const A b{1,1}; // const修饰自定义类型会分配内存

    return 0;
}