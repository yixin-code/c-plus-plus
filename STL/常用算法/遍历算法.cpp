#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 基本用法
void test1()
{
	vector<int> v = { 1,2,3,4,5,6 };
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//返回值
class Person1 : public binary_function<int, int, void>
{
public:
	void operator()(int val)
	{
		cout << val << " ";
		this->m_count++;
	}

	void operator()(int val, int num) const
	{
		cout << val + num << " ";
	}

	int m_count = 0;
};

void test12()
{
	vector<int> v = { 1,2,3,4,5,6 };
	// 返回值就是仿函数的对象
	Person1 p = for_each(v.begin(), v.end(), Person1());
	cout << endl;
	cout << p.m_count << endl;
}

// 适配器
void test13()
{
	vector<int> v = { 1,2,3,4,5,6 };
	// 返回值就是仿函数的对象
	int num = 11;
	auto func = bind2nd(Person1(), num);
	for_each(v.begin(), v.end(), func);
	cout << endl;
}

// 可将元素按规则搬运到另一个容器
// transform 不会为v2分配内存
void test14()
{
	vector<int> v = { 11,22,33,44,55 };
	vector<int> v2(v.size());

	transform(v.begin(), v.end(), v2.begin(), [](int val) {return val - 10; });

	for (auto val : v2)
	{
		cout << val << " ";	//1 12 23 34 45
	}
	cout << endl;

	// 可将两个容器的元素按一定规则搬运到另一个容器
	vector<int> v3(v.size()); // 为v3分配空间

	transform(v.begin(), v.end(), v2.begin(), v3.begin(), [](int val, int val2) {
		return val + val2;
		});
	for (auto val : v3)
	{
		cout << val << " ";
	}
	cout << endl;
}

int main()
{
	//test12();
	//test13();
	test14();

	return 0;
}