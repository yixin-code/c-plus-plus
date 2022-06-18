// 空指针访问成员函数
#include <iostream>

using namespace std;

class Test
{
private:
    int m_a;

public:
    Test() {}
    void display() 
    {
        cout << "display" << endl;
    }
    //上述代码相当于
    // void display(Test *this) // 虽有this指针但是并没有使用 所以无影响
    // {
    //     cout << "display" << endl;
    // }

    void displayA()
    {
        // 解决这种异常可以加this是否为空判断
        if (this == nullptr)
        {
            return;
        }
        cout << "displayA " << m_a << endl;
    }
    //上述代码相当于
    // void displayA(Test *this)
    // {
    //     cout << "displayA" << this->m_a << endl; // 使用this 相当于 nullptr->m_a
    // }

    ~Test() {}
};

int main(int argc, char *argv[])
{
    // 创建一个指向类的空指针
    Test *p = nullptr;
    p->display();
    p->displayA(); // error

    return 0;
}