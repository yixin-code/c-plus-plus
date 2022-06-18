#include <iostream>

using namespace std;

class A // 类对象只包含成员变量， 成员函数在公共代码区， 由this指针调用
{
private:
    int m_a;

public:
    A(/* args */) { m_a = 0; }
    
    // 函数值传递会调用拷贝构造函数
    // 当不返回引用时， 返回值相当于值传递会调用拷贝构造函数
    // 返回的并不是对象本身， 而是一个临时值, 如下代码最后的结果只是1
    // A func() 
    A &func() 
    {
        m_a++;
        return *this;
    }
    void display()
    {
        cout << this->m_a << endl;
    }
    ~A() {}
};

int main(int argc, char *argv[])
{
    // this指针指向被调用成员函数所指对象
    // this指针永远指向当前对象 int *const
    // 静态成员没有this指针
    // 成员变量和参数相同时this可以解决命名冲突
    // return *this可以返回当前对象本身, 返回引用时函数可以作为左值
    A a;
    a.func().func().func();
    a.display();

    return 0;
}