// 异常类
// 从try开始到throw抛出异常之前所有栈上对象都会被释放, 这个过程叫栈解旋
// 异常的声明周期只有栈解旋的过程，(捕获是使用引用, 别搞花里胡哨 )
// 如果抛出的是地址异常捕获的时候会提前释放，无法调用成员函数, 需要在堆上创建
#include <iostream>

using namespace std;

class MException
{
public:
    void e_int()
    {
        std::cout << "num2 is 0" << std::endl;
    }
};

int dev(int num, int num2)
{
    if (num2 == 0)
    {
        throw MException();
    }
    return num / num2;
}

void test()
{
    try
    {
        dev(1, 0);
    }
    catch (MException &e)
    {
        e.e_int();
    }
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}