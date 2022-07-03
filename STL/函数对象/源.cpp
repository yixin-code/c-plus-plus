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
	
	// ���Ա���״̬
	int m_count = 0; 
};

// �����������������
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