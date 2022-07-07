#include <iostream>

using namespace std;

void cFunc()
{
    char buf[3];
    
    // scanf("%s", buf); // 输入 asdfg
    // printf("buf = %s\n", buf); // asdfg 在增加输入程序会挂

    // gets(buf); // 输入 asdfg
    // printf("buf = %s\n", buf); // 效果同上

    // 安全的
    fgets(buf, 3, stdin); // asdfg
    printf("buf = %s\n", buf); // as
}

void cppFunc()
{
    char buf[3];
    
    // cin >> buf; // 效果同上
    // cout << buf << endl;

    // 安全的
    cin.getline(buf, 3);
    cout << buf << endl;
}

int main()
{
    // cFunc();
    cppFunc();

    return 0;
}