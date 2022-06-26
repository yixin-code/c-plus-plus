#include <iostream>

using namespace std;

void test()
{
    int num = 0;
    cout << "input num:" << endl;
    while (true) // 错误输入时标志位会变成1
    {
        cin >> num;
        if (cin.fail())
        {
            cin.clear(); // 重置标志位 默认为0
            cin.sync();  // 清空缓存区
        }
        else
        {
            break;
        }
    }
    cout << num << endl;
}

int main(int argc, char *argv[])
{
    test();

    return 0;
}