// 模板会编译两次，对模板本身进行一次编译， 在调用时参数替换再次进行编译
#include <iostream> 

template<class T>
void mSwap(T &num, T &num2)
{
	std::cout << "函数模板" << std::endl;
	T temp = num;
	num = num2;
	num2 = temp;
}

// 函数模板可以和普通函数进行重载， 会优先调用普通函数
void mSwap(int &num, int &num2)
{
	std::cout << "普通函数" << std::endl;
	int temp = num;
	num = num2;
	num2 = temp;
}

// 函数模板本身可以重载， 
template<class T>
void mSwap(T &num, T &num2, T &num3)
{
	std::cout << "模板可以进行重载" << std::endl;
	T temp = num;
	num = num2;
	num2 = temp;
}

void test()
{
	int num = 11;
	int num2 = 22;

	// 自动类型推倒
	mSwap(num, num2);
	std::cout << num << " " << num2 << std::endl;

	// 指定类型
	mSwap<int>(num, num2);
	std::cout << num << " " << num2 << std::endl;
}

void test2()
{
	int num = 11;
	int num2 = 22;
	int num3 = 33;

	// 有限调用普通函数
	mSwap(num, num2);
	std::cout << num << " " << num2 << std::endl;
	std::cout << "----------------------------" << std::endl;

	// 加<>可以强制调用模板函数
	mSwap<int>(num, num2);
	std::cout << num << " " << num2 << std::endl;
	std::cout << "----------------------------" << std::endl;

	// 模板函数不能进行隐士类型转换 error
	// char c = 'a';
	// mSwap<>(num, c);
	// std::cout << num << " " << num2 << std::endl;
	// std::cout << "----------------------------" std::endl;

	// 模板可以进行重载
	mSwap<int>(num, num2, num3);
	std::cout << num << " " << num2 << std::endl;
}

int main()
{
	// test();
	test2();

	return 0;
}
