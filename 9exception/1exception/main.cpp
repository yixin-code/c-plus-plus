// 异常基本使用
#include <iostream>

using namespace std;

int dev(int num, int num2)
{
    if (num2 == 0)
    {
        throw -1;
    }
    return num / num2;
}

void test()
{
    try
    {
        dev(1, 0);
    }
    // catch (int)
    // {
    //     cout << "num2为0" << endl;
    // }
    // 如果不处理可以继续向上抛
    catch (int)
    {
        throw;
    }
}

void test2()
{
    try
    {
        test();
    }
    catch (int)
    {
        cout << "num2为0" << endl;
    }

}

int main(int argc, char *argv[])
{
    // test();
    test2();

    return 0;
}