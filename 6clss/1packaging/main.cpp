#include <iostream>

using namespace std;

class A
{
private:   // 私有成员， 类外不可访问
public:    // 公有成员， 类外可以访问
protected: // 保护成员， 类外不可访问， 子类可以访问
};

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

int main(int argc, char *argv[])
{
    B b{11};
    b.setA(22);
    b.display();

    B b2;
    b2.display();

    return 0;
}