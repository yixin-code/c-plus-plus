//在堆上建立一个对象，用new。分配内存又为对象调用构造函数。
//只分配内存，调用operator new函数；不会调用构造函数。
//operator new可以重载函数。使用new操作符，new操作符会调用你定制的operator new。
//在一块已经获得指针的内存里建立一个对象。用placement new。 (需要添加new头文件)
#include <iostream>
#include <string>
#include <new> // placement new

using namespace std;

// new operator
// 分配内存 调用构造函数初始化
void test()
{
	string* str = new string("hello world");

	cout << *str << endl;

	delete str;
}

// operator new
// 用来分配内存的函数，为new操作符调用。能够被重载（有限制）
// 原型 void * operator new(size_t size);
void test2()
{
	//int* num = new int[sizeof(int)]; 和下面是等价的
	int* num = (int *)operator new(sizeof(int));

	*num = 10;

	cout << *num << endl;

	delete num;
}

// placement new
// placement new是特殊的operator new，作用于一块已分配但未处理或未初始化的内存
// 就是在已经获取的内存上新建一个对象，比重新申请内存要快
void test3()
{
	int* arr = new int[99];
	// 在arr空间上新建一个string对象
	string* str = new(arr) string("hello world");

	cout << *str << endl;

	delete[] arr;
}

int main()
{
	test();
	test2();
	test3();

	return 0;
}