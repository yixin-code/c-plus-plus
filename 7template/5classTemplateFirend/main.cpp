#include <iostream>
#include <string>

// 编译器找不到A类, 还需要前置声明A类
template <class ValType, class ValType2>
class A;

// 类内声明display, 它是一个全局函数可是其中有内模板A, 编译器无法找到, 需要声明函数
template <class ValType, class ValType2>
void display(A<ValType, ValType2> &a);

template <class ValType, class ValType2>
class A
{
    // 直接写到类中很简单
    // friend void display(A<ValType, ValType2> &a)
    // {
    //     std::cout << a.val << " " << a.val2 << std::endl;
    // }

    // 写在类外很麻烦
    // 因为类外需要定义模板函数, 所以类内需要指定调用模板函数
    friend void display<>(A<ValType, ValType2> &a);

private:
    ValType val;
    ValType2 val2;

public:
    A()
    {
        this->val = 11;
        this->val2 = "aaa";
    }
};

template <class ValType, class ValType2>
void display(A<ValType, ValType2> &a)
{
    std::cout << a.val << " " << a.val2 << std::endl;
}

int main()
{
    A<int, std::string> a;
    display(a);

    return 0;
}