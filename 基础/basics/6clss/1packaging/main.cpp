#include <iostream>

using namespace std;

class A // 空类的时候大小是一个字节
{
private:   // 私有成员， 类外不可访问
    int m_a;
public:    // 公有成员， 类外可以访问
protected: // 保护成员， 类外不可访问， 子类可以访问
};

int main()
{
    // 空类的时候1个字节，因为空类也可以创建对象，系统用一个char来维护这个地址
    cout << sizeof(A) << endl;
    
    // 当类中有成员变量时,大小就是正常结构大小
    // 静态成员函数和成员变量，还有不同成员函数并不在某一个对象中, 不会改变一个类的大小
    // 成员函数和成员对象是分开存储的

    return 0;
}

// C++中结构体也可以这么玩， 只是默认权限是public, 而且没有this指针
struct B
{
    B(){};
    B(int b) { a = b; }
    void setA(int temp)
    {
        a = temp;
    }
    void display()
    {
        cout << a << endl;
    }

private:
    int a = 33; // 也可以有默认值
};

int main2(int argc, char *argv[])
{
    B b{11};
    b.setA(22);
    b.display();

    B b2;
    b2.display();

    return 0;
}