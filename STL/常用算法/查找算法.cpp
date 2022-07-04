#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// find在区间内查找元素， 找到返回迭代器， 未找到返回指定的结束迭代器
// 自定义类型需要重载==
void test2()
{
	vector<int> v = { 1,2,3,4,5 };
	auto it = find(v.begin(), v.begin() + 4, 11);
	if (it != v.begin() + 4)
	{
		cout << *it << endl;	//4
	}
	else
	{
		cout << *it << endl;
	}
}

// 条件查找
class Person2
{
public:
	Person2(int age, string name)
	{
		this->m_age = age;
		this->m_name = name;
	}
	bool operator==(Person2 p)
	{
		return this->m_age == p.m_age && this->m_name == p.m_name;
	}
	bool operator==(Person2* p)
	{
		return this->m_age == p->m_age && this->m_name == p->m_name;
	}

	string m_name;
	int m_age;
};

void test22()
{
	vector<Person2*> v;
	Person2 p(1, "aa");
	Person2 p2(2, "bb");
	Person2 p3(3, "cc");
	Person2 p4(4, "dd");
	Person2 p5(5, "ee");
	v.emplace_back(&p);
	v.emplace_back(&p2);
	v.emplace_back(&p3);
	v.emplace_back(&p4);
	v.emplace_back(&p5);

	Person2 p6(3, "cc");
	// test
	//if (p3 == p6)
	//{
	//	cout << "p3 == p6" << endl;
	//}
	auto it = find_if(v.begin(), v.end(), [=](Person2* p) {
		return *p == p6;
		});

	if (it != v.end())
	{
		cout << (*it)->m_name << " " << (*it)->m_age << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
}

// 区间查找
void test23()
{
	vector<int> v = { 1,2,3,4,5 };
	vector<int> v2 = { 9,5,11 };
	auto it = find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
	if (it != v.end())
	{
		cout << *it << endl;	//5
	}

	auto it2 = find_first_of(v.begin(), v.end(), v2.begin(), v2.end(), [](int val, int val2) {return ((val + 4) == val2); });
	if (it2 != v.end())
	{
		cout << *it2 << endl;	//1
	}
}

// 条件查找不匹配
void test24()
{
	vector<int> v = { 1,2,3,4,5 };
	auto it = find_if_not(v.begin(), v.end(), [](int val) {return val > 3; });
	if (it != v.end())
	{
		cout << *it << endl;	//1
	}
}

// 查找相邻元素
void test25()
{
	vector<int> v = { 1,2,3,4,4,5,7,6,9,8,8 };
	auto it = v.begin();

	it = adjacent_find(v.begin(), v.end());

	cout << *it << endl;	//4

	it = adjacent_find(it, v.end(), [](int val, int val2) {
		return val > val2;
		});

	cout << *it << endl;	//7
}

// 二分查找
void test26()
{
	//要使用二分查找必须是有序的序列
	vector<int> v = { 1,2,3,4,5,6,7 };

	if (binary_search(v.begin(), v.end(), 6))
	{
		cout << "found" << endl;
	}
}

// 查找元素个数
void test27()
{
	vector<int> v = { 1,2,3,4,5,5,5,6,7 };

	int my_count = count(v.begin(), v.end(), 5);
	cout << my_count << endl;	//3
}

// 查找符合条件的元素个数
void test28()
{
	vector<int> v = { 1,2,3,4,5,5,5,6,7 };

	int my_count = count_if(v.begin(), v.end(), [](int val) {return val % 2; });
	cout << my_count << endl;	//6
}

int main2()
{
	//test2();
	//test22();
	test25();

	return 0;
}