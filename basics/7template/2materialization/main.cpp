// 模板实例化
#include <iostream>

class A
{
private:
    int m_num;

public:
    A()
    {
        this->m_num = 11;
    }
    int getNum() const
    {
        return this->m_num;
    }
};

template <class T>
bool mCompare(T &val, T &val2)
{
    if (val == val2)
    {
        return true;
    }
    return false;
}

// 模板实例化
template <>
bool mCompare<A>(A &val, A &val2)
{
    if (val.getNum() == val2.getNum())
    {
        return true;
    }
    return false;
}

void test()
{
    int num = 11;
    int num2 = 22;

    std::cout << mCompare(num, num2) << std::endl;

    A a;
    A a2;
    // 自定义类型无法比较 可以添加运算符重载， 或模板实例化
    std::cout << mCompare(a, a2) << std::endl;
}

int main()
{
    test();

    return 0;
}