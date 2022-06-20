// 不要重载 && 和 || 会造成原本的短路特性失效
#include "Num.h"
#include "SmartPoint.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    Num n(11, 11);
    n.display();
    Num n2(22, 11);
    n2.display();
    Num n3 = n + n2;
    n3.display();
    Num n4 = n3 + 11;
    n4.display();

    cout << "______________________________" << endl;
    
    cout << n4 << endl;

    cout << "______________________________" << endl;

    // cin >> n4;
    // cout << n4 << endl;

    cout << "______________________________" << endl;

    cout << ++n4 << endl;

    // Num temp = n4++;
    // cout << temp << endl;

    // 以前真没有发现 g++ 真的优化了好多啊
    // std::ostream &operator<<(std::ostream &out, Num &n) 引用是可以做左值的操作数
    // Num Num::operator++(int) 是值返回， 只能做右值
    // 解决方法 
    // 添加重载 std::ostream &operator<<(std::ostream &out, Num n)
    // 或 std::ostream &operator<<(std::ostream &out,const Num &n)
    cout << n4++ << endl;

    cout << "______________________________" << endl;

    SmartPoint sp(new Num);
    SmartPoint sp2(new Num(22, 22));

    sp->display();
    (*sp).display();

    sp2->display();
    (*sp2).display();

    cout << "______________________________" << endl;

    Num n5 = n4;
    cout << n5 << endl;

    cout << "______________________________" << endl;

    n5[0] = 'x';
    cout << n5 << endl;

    if (n5 == n4)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }

    n5("aaa");
    // 匿名对象调用仿函数
    Num()("bbbb");

	// getchar();
    return 0;
}