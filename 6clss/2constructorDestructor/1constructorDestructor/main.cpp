#include "test.h"

using namespace std;

void test(A a)
{
}

void test2(A &a)
{
}

A test3()
{
    A a;
    return a;
}

void func()
{
    A a;          // 调用无参构造
    A a2(11);     // 调用有参构造
    A a3(a2);     // 调用拷贝构造
    A a4 = A(11); // 匿名对象形式(匿名对象执行结束就会释放)， 调用有参构造
}

// 拷贝构造调用时机
void func2()
{
    A a(11);
    A b(a);        // 用已创建好的对象初始化新对象
    test(b);       // 参数值传递时
    test2(b);      // 传引用的时候不会调用任何构造函数， 可以减少开销
    A c = test3(); // 函数返回值, VS中会调用拷贝构造(release优化下也不会)， gcc中不会 
}

int main(int argc, char *argv[])
{
    // func();
    func2();

	getchar();

    return 0;
}