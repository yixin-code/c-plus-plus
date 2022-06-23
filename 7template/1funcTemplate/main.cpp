#include <iostream> 

template<class T>
void swap(T &num, T &num2)
{
	T temp = num;
	num = num2;
	num2 = temp;
}

int main()
{
	int num = 11;
	int num2 = 22;

	// 自动类型推倒
	swap(num, num2);
	std::cout << num << " " << num2 << std::endl;

	// 指定类型
	swap<int>(num, num2);
	std::cout << num << " " << num2 << std::endl;

	return 0;
}
