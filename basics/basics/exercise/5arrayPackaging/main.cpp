#include "Array.h"
#include <iostream>

using namespace std;

void func()
{
    Array a(11);              // 有参构造
    Array *b = new Array(a);  // 拷贝构造
    Array *c = new Array(*b); // 拷贝构造
    Array d(*c);              // 拷贝构造

    d.pushBack(1);
    d.pushBack(2);
    d.pushBack(3);

    // 这样写每次都会进入getSize, 浪费大量时间
    for (int i = 0; i < d.getSize(); ++i)
    {
        cout << d[i] << endl;
    }

    cout << "________________________" << endl;

    for (int i = 0; i < d.getSize(); ++i)
    {
        d[i] = i + 11;
    }

    for (int i = 0; i < d.getSize(); ++i)
    {
        cout << d[i] << endl;
    }

    delete b;
    delete c;
}

int main(int argc, char *argv[])
{
    func();

    return 0;
}