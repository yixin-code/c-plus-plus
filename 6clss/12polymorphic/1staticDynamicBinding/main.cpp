// 父类指针或引用指向子类对象
// 多态利于后期扩展，结构好，可读性高，但由于内部结构效率稍低（和C相比）
// 普通析构函数在多态的时候无法准确调用， 需要虚析构函数, 在析构函数前 virtual
// 纯虚析构，也需要实现，不然父类无法调用
// 抽象类无法实例化， 纯虚函数子类必须重写
#include <iostream>

using namespace std;

class A
{
public:
    // void func()
    virtual void func() // 当函数为虚函数时会发生动态联编（多态） 实现时不需要限定符
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    // 子类会继承虚函数表指针和虚函数表
    // 重写父类虚函数， 会覆盖掉父类的虚函数， 使虚函数表指针指向自己的虚函数
    void func() 
    {
        cout << "B" << endl;
    }
};

void test(A &a)
{
    a.func();
}

// void work()
// {
//     // 静态联编 在编译阶段绑定地址
//     B b;
//     test(b);
// }

void work2()
{
    // 动态联编 在运行阶段绑定地址
    B b;
    test(b);
}

int main(int argc, char *argv[])
{
    // work();
    work2();

    return 0;
}