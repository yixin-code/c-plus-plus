// 标准输入流
#include <iostream>

using namespace std;

void xget()
{
    char a = cin.get(); // 读取一个字符， 换行符会在缓冲区中
    cout << "a = " << a << endl;
    char b;
    cin.get() >> b;
    cout << "b = " << b << endl;
}

void xget2()
{
    char buf[1024]{0};
    cin.get(buf, 1024); // 读取字符串， 换行符会在缓冲区中
    cout << buf << endl; 
    char a = 0;
    cin.get() >> a;
    cout << "b = " << a << endl;

    string str;
    
}

void xgetline()
{

}

void xignore()
{
    char a = 0;
    cin.ignore(3) >> a; // 忽略几个字符
    cout << a << endl;
}

void xpeek()
{
    char a = 0;
    a = cin.peek(); // 不会从缓冲区拿走字符
    cout << a << endl;
    char b = cin.get();
    cout << "b = " << b << endl;
}

void xputback()
{
    // char buf[1024]{0};
    // cin.getline(buf, 1024); // 读取字符串会舍弃换行符
    // cout << buf << endl; 
    // cin.putback('a');
    // char a = cin.get();
    // cout << a << endl;

    cin.putback('x'); // 将一个字符放回缓冲区
    char b = cin.get();
    cout << b << endl;
}

int main(int argc, char *argv[])
{
    // xget();
    // xget2();
    // xignore();
    // xpeek();
    // xputback();

    return 0;
}