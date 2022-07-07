#include <iostream>

using namespace std;

// 只能在全局下声明
namespace A
{
    int a = 11;
    
    void func();

    struct A
    {
        int m_a;
    };

    class B
    {
    private:
        int m_b;
    public:
        B(/* args */) {}
        ~B() {}
    };

    namespace C
    {
        int c;
    }
    
} // namespace A

// 两个namespace A 会合并在一起
namespace A
{
    int d;
}

// 匿名相当于 static int a;
namespace 
{
    int a;
} // namespace 

namespace C
{
    int d;
} // namespace C


int main(int argc, char *argv[])
{
    A::a = 111;
    cout << "A::a" << A::a << endl;

    // int d = 1111;
    // using namespace A;
    // cout << "d = " << d << endl; // 1111 会使用就近原则 

    // int d = 1111;
    // using A::d;
    // cout << "d = " << d << endl; // 会产生二义性

    // 都有变量d同样会产生二义性
    // using namespace A;
    // using namespace C;

    return 0;
}