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

    // cin >> ms;
    // cout << ms << endl;
    cout << "___________________________"<< endl;

    ms3 = ms4 + ms;
    cout << ms3 << endl;
    ms3 = ms4 + "xxx";
    cout << ms3 << endl;
    cout << "___________________________"<< endl;

    if (ms == ms2)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }

    cout << ms.getSize() << endl;
}

int main()
{
    test();

    return 0;
}