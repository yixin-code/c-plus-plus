// 模板类继承
#include <iostream>

template <class T>
class A
{
private:
    T m_val;
};

// 必须指定父类类型, 否则无法为父类分配空间
class B : public A<int>
{
private:
    int m_val;
};

// 也可以全部模板化
template <class CType, class AType>
class C : public A<AType>
{
private:
    CType m_val;
};

int main()
{
    A<int> a;
    B b;
    C<int, int> c;

    return 0;
}