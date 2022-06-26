// 多态异常类
// 直接去源码中找
#include <iostream>
#include <exception>

using namespace std;

class NullPointer : public exception
{
public:
    const char * what () const  _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return "null pointer";
    }
    ~NullPointer() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        cout << "null pointer destruct" << endl;
    }
};

class Overstep : public exception
{
public:
    const char * what () const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return "over step";
    }
    ~Overstep() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        cout << "over step destruct" << endl;
    }
};

void func()
{
    throw NullPointer(); // 匿名对象
}

void func2()
{
    throw Overstep(); // 匿名对象
}

int main(int argc, char *argv[])
{
    try
    {
        func();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        func2();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}