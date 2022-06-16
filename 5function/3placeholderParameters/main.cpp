#include <iostream>

using namespace std;

// c中没有
// 占位参数 随便传值 实际用途好像只有重载自增自减
void func(int a, int)
{
    cout << a << endl;
}

int main(int argc, char *argv[])
{
    func(11, 11);

    return 0;
}