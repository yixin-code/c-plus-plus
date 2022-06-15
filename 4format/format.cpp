#include <iostream>
#include <iomanip> // format 头文件

using namespace std;

void func()
{
    int a = 11;
    cout << hex << a << endl; // 16进制
    cout << dec << a << endl; // 10进制
    cout << oct << a << endl; // 8进制
}

void func2()
{
    double a = 11.11; // float 有效6位 double 有效15位 
    cout << "宽度：" << endl;
    cout << a << endl; 
    cout << "宽度：" << setw(11) << a << endl;
    cout << "宽度：" << setw(11) << setiosflags(ios::left) << a << "输出在左边" << endl;
    
    // 宽度填充字符
    // setw只生效一次
    int a2 = 11, b = 8, c = 32;
    cout << setfill('0') << setw(2) << a2 << ":" << setw(2) << b << ":" << setw(2) << c << endl;

    cout << "精度" << endl;
    double d = 1.23456789;
    cout << "包括整数" << setprecision(2) << d << endl; // 1.2
    cout << "小数" << setprecision(2) << setiosflags(ios::fixed) << d << endl; // 1.23
}

int main()
{
    // func();
    func2();

    return 0;
}