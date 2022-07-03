#include <iostream>

using namespace std;

class MyClass
{
public:
	void operator()(std::string str)
	{
		cout << "hello world" << endl;
		cout << str << endl;
		this->m_count++;
	}
	
	// 可以保存状态
	int m_count = 0; 
};

// 函数对象可以做参数
void test(MyClass& mc, std::string str)
{
	mc(str);
}

int main()
{
	MyClass func;
	func("hello cpp");
	cout << "func call " << func.m_count << endl;
	func("hello cpp");
	cout << "func call " << func.m_count << endl;
	func("hello cpp");
	cout << "func call " << func.m_count << endl;
	func("hello cpp");
	cout << "func call " << func.m_count << endl;
	func("hello cpp");
	cout << "func call " << func.m_count << endl;
	test(func, "hello stl");
	cout << "func call " << func.m_count << endl;

	return 0;
}