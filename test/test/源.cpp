//深入理解 C++ String 在内存中的布局：
//名称	X86(字节数)	X64（字节数）
//Allocator	4	8
//原始字符传 Data 位置(小于15个字符开辟在栈上，大于开辟在堆上)	15 + 1  最多包含15个字符加一个结束符‘\0’	15 + 1  最多包含15个字符加一个结束符‘\0’
//字符长度 Size	4	8
//当前容量 Capacity	4	8
//总计	28	40
#include <iostream>

using namespace std;

int main()
{
	string str;
	cout << sizeof(str) << endl; // 40
	cout << sizeof(string) << endl; // 40

	return 0;
}