//set是键的集合, 当需要知道一个值是否存在的时候使用set再合适不过.
//set不能进行下标操作.
//set是唯一内的值是唯一的, multiset中的值可以不唯一
#include <iostream>
#include <set>

using namespace std;

bool funcComp(int val, int val2)
{
	return val > val2;
}

class Comp
{
public:
	bool operator()(const int val, const int val2)const
	{
		return val > val2;
	}
};

// 构造
void test()
{
	//无参构造函数
	set<int> s;

	//数组范围有参构造
	int arr[] = { 1,2,3,4,5,6 };
	set<int> s2(arr, arr + 6);

	//复制构造
	set<int> s3(s2);

	//迭代器有参构造
	set<int> s4(s3.begin(), s3.end());

	//改变排序规则构造,默认升序
	//直接赋值
	//C++ 并不能完全解决C的问题， 在C++里就老老实实的用C++的东西
	set<int, Comp> s5 = { 1,2,3,4,5,6 };
	bool(*p)(int, int) = funcComp;
	set<int, bool(*)(int, int)> s6(p); // 需要传类型
	s6 = { 1,2,3,4,5,6,7,8,9 };

	for (auto it = s6.begin(); it != s6.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 插入元素
void test2()
{
	set<int> s;
	set<int> s2 = { 5,32,45,324,543,5,435,4325 };

	//插入一个元素返回指向这个元素的迭代器
	auto ret = s.insert(s.begin(), 9);
	cout << *ret << endl << endl;	//9

	//插入一个元素返回一个对组,第一个元素为指向这个元素的迭代器,第二个元素是bool值判断是否插入成功
	auto ret2 = s.insert(7);
	cout << *ret2.first << " " << ret2.second << endl << endl;	//7 1

	//插入一个迭代器区间,无返回值
	s.insert(s2.begin(), s2.end());

	//C++11  插入效率更高
	//插入一个元素返回一个对组,第一个元素为指向这个元素的迭代器,第二个元素是bool值判断是否插入成功
	auto ret3 = s.emplace(2);
	cout << *ret3.first << " " << ret3.second << endl << endl;	//2 1

	//C++11 插入一个元素返回指向这个元素的迭代器
	auto ret4 = s.emplace_hint(s.begin(), 6);
	cout << *ret4 << endl << endl;	//6
}

// 删除 
void test3()
{
	set<int> s = { 3,4,5,1,23,5,325,5,6,32,1,1,434,4 };
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//按迭代器位置删除
	//auto it = s.begin();
	//it + 3;	//不支持随机访问 也不支持下标操作
	//s[4];	
	s.erase(s.begin());

	//按迭代器区间删除
	auto it = s.begin();
	++it;
	++it;
	++it;
	s.erase(s.begin(), it);

	//按key删除 删除所有符合的元素,返回删除的元素个数(set中不能重复key所以只能返回1和0)
	auto i = s.erase(1);
	cout << i << endl << endl;

	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//清空元素
	s.clear();
}

// 查找
void test4()
{
	set<int> s = { 4,2,1,5,6,8,9 };

	//查找,找到返回指向这个元素的迭代器,没有找到返回结束迭代器
	auto it = s.find(5);
	if (it != s.end())
	{
		//*it = 10;	//error
		cout << *it << endl << endl;	//5
	}

	multiset<int> ms = { 1,2,3,4,2,3,2,3,5,65,5,5,5,5,5 };
	auto it2 = ms.find(5);
	if (it2 != ms.end())
	{
		//*it2 = 10;	//error
		cout << *it2 << endl << endl;	//5
	}

	// 没有找到返回结束迭代器
	//返回 >= 或 > 两个元素的迭代器 一个对组(数据中没有3)
	auto ret = s.equal_range(3);
	cout << *ret.first << " " << *ret.second << endl;	//4 4
	ret = s.equal_range(4);
	cout << *ret.first << " " << *ret.second << endl << endl;	//4 5

	//返回 >= 元素的迭代器
	auto ret2 = s.lower_bound(3);
	cout << *ret2 << endl; //4
	ret2 = s.lower_bound(4);
	cout << *ret2 << endl << endl; //4

	//返回 > 元素的迭代器
	auto ret3 = s.upper_bound(3);
	cout << *ret3 << endl; //4
	ret3 = s.upper_bound(4);
	cout << *ret3 << endl << endl; //5
}

void test5()
{
	set<int> s;

	//判断set是否为空
	if (s.empty())
	{
		cout << "is empty" << endl << endl;
	}

	//返回一个元素的元素个数
	s = { 1,2,4,5,6,3 };
	multiset<int> s2 = { 1,1,2,2,3,3,4,4,5,5 };
	cout << s.count(7) << endl;	//0
	cout << s.count(5) << endl << endl;	//1

	cout << s2.count(7) << endl;	//0
	cout << s2.count(5) << endl << endl;	//2

	//容纳最大元素数量
	cout << s2.max_size() << endl;

	//返回当前元素个数
	cout << s2.size() << endl;	//6

	//交换两个set
	set<int> s3 = { 1,2,3 };
	s3.swap(s);
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	for (auto it = s3.begin(); it != s3.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	//元素间进行比较默认升序
	set<int> s4 = { 34,24,643,14 };
	cout << s4.key_comp()(1, 2) << endl;	//1
	cout << s4.key_comp()(14, 34) << endl;	//1
	cout << s4.key_comp()(2, 1) << endl;	//0

	cout << s4.value_comp()(1, 2) << endl;	//1
	cout << s4.value_comp()(14, 24) << endl;	//1
	cout << s4.value_comp()(34, 14) << endl;	//0
}

int main()
{


	return 0;
}
