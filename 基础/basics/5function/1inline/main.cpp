#define ADD(a, b) ((a) + (b))
#include <iostream>

using namespace std;

// 内联函数相对宏更加灵活
// 声明实现都需要加inline
// 普通函数需要入栈出栈等开销， 内联函数和宏一样是直接替换
// inline只是对编译器的建议， 具体实现与否都是编译器行为
// 循环，过多的判断， 函数体过大， 对函数进行取址操作都不会是内联函数
inline int func(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    int a = 11, b = 22; 
    cout << ADD(a, b) << endl;
    cout << func(a, b) << endl;

    return 0;
}