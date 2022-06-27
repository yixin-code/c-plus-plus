#include "test.h"

// g++中居然不行? 原来是为了方便运行 我把配置文件改了。。。
int main()
{
    // C++会重载，编译器会给函数改名
    // C中没有函数重载， 不会给函数改名，没有声明报链接错误
    // 需要extern c
    func();

	getchar();

    return 0;
}