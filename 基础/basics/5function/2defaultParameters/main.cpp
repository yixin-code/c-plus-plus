#include <iostream>

using namespace std;

// C中没有
// 声明和实现中只能有一个存在默认参数
// 默认参数必须从最右边开始, 注意函数重载二义性
void func(int a, int b, int c = 11)
{
    cout << a << " " << b << " " << c << endl;
}

// void func(int a, int b)
// {
//     cout << a << " " << b << endl;
// }

int main(int argc, char *argv[])
{
    func(1, 2);
    func(1, 2, 3);

    return 0;
}