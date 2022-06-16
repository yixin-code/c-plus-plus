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


int main(int argc, char *argv[])
{
    

    return 0;
}