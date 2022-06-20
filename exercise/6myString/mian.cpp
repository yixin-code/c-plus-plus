#include <iostream>
#include "MyString.h"

using namespace std;

void test()
{
    MyString ms;
    MyString ms2("aaa");
    cout << ms2 << endl;
    MyString ms3(ms2);
    cout << ms3 << endl;
    MyString ms4 = ms3; // 拷贝构造
    cout << ms4 << endl;
    ms = ms4;
    cout << ms << endl;
    cout << "___________________________"<< endl;

    cin >> ms;
    cout << ms << endl;
}

int main()
{
    test();

    return 0;
}