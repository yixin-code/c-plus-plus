// 所有对象可以共享数据， 在编译阶段分配内存
// 类内声明， 类外初始化（17之后可以加关键字inline对其进行初始化）
// 可通过类名访问
#include <iostream>

using namespace std;

class A
{
public:
    static int s_num;
};

int A::s_num = 11;

int main(int argc, char *argv[])
{
    A a;
    a.s_num = 22;
    A b;    
    b.s_num = 33;

    cout << A::s_num << endl;

    A c;
    cout << c.s_num << endl;

    return 0;
}