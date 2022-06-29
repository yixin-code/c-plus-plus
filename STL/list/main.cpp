//列表(list)
//一个双向循环链表, 相对vector的联系空间, list复杂很多, 它可以快速的插入和删除, 但是随机访问比较慢.
//因为是链表实现, 所以他不会造成空间浪费.
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 构造 分配
void test()
{
	//其实容器内的函数都差不多,构造函数基本和vector完全一样
	list<int> l;	//创建一个空的list
	list<int> l2(3);	//创建一个含有3个元素的list
	list<int> l3(3, 1);	//创建一个含有3个元素的list,每个都初始化为1
	list<int> l4(l3);	//创建一个list,并用l3对齐进行初始化
	list<int> l5(l4.begin(), l4.end());	//用迭代器进行初始化

	//也可以为其分配值
	l.assign(l4.begin(), l4.end());
	l2.assign(3, 1);	//为其赋值3个1

	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	list<int> l6(arr, arr + 10);	//使用数组对其进行初始化

	//遍历
	//for (list<int>::iterator it = l5.begin(); it != l5.end(); ++it)
	for (auto it = l6.begin(); it != l6.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//定义一个迭代器
	auto it = l6.begin();

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	auto it2 = v.begin();
	//it + 2;	//错误不支持随机访问
	it2 + 2;	//correct

	cout << *(it2 + 2) << endl;
}

// 迭代器
void test2()
{
	list<int> l;
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	l.assign(arr, arr + 10);

	//正向迭代器
	auto it_end = l.end();
	//cout << *it_end << endl;	//程序会蹦 指向的是最后一个元素的下一位置

	auto it_begin = l.begin();
	cout << *it_begin << endl;	//输出的是第一个元素 1

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	cout << endl;
	cout << endl;

	//逆向迭代器
	auto rit_end = l.rend();
	//cout << *rit_end << endl;	//同样会崩 指向第一个元素的上一位置

	auto rit_begin = l.rbegin();
	cout << *rit_begin << endl;	//输出的是最后一个元素 0

	for (auto it = l.rbegin(); it != l.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

// 增加元素
void test3()
{
	list<int> l;
	int arr[] = { 1,2,3,4,5 };
	vector<int> v(arr, arr + 5);

	//后插
	l.push_back(1);

	//前插
	l.push_front(2); //2 1

	//插入 插入到迭代器位置 返回插入迭代器位置
	auto it = l.insert(l.begin(), 3);	//3 2 1
	cout << *it << endl;	//3

	//插入3个1到迭代器位置 无返回值
	l.insert(l.begin(), 3, 1);	//111321

	//插入迭代器区间数据到迭代器位置
	l.insert(l.begin(), arr, arr + 5);	//12345111321
	l.insert(l.begin(), v.begin(), v.end());	//1234512345111321

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1234512345111321
	}
	cout << endl;
}

// 谓词

//函数形式谓词
bool func(int& val)
{
	return val < 6;
}

//仿函数形式谓词
class functor
{
public:
	bool operator()(int& val)
	{
		return val < 6;
	}
};

bool func2(int val, int val2)
{
	return val > val2;
}

// 删除元素
void test4()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0 };
	list<int> l(arr, arr + 20);

	//删除迭代器指定位置
	l.erase(l.begin());	//23456789012345

	//删除指定迭代器区间
	auto it = l.begin();
	it++;
	it++;
	//it + 1;	不能随机访问的迭代器这样加1也是不可以的
	l.erase(l.begin(), it);	//45678901234567890

	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//45678901234567890
	}
	cout << endl;

	//按值删除元素,删除list所有这个值的元素
	l.remove(4);	//567890123567890

	//按条件删除,需要谓词
	//两效果是等价的
	//l.remove_if(func);
	l.remove_if(functor());	//67896789

	//删除第一个元素
	l.pop_front();	//7896789

	//删除最后一个元素
	l.pop_back();	//789678

	//删除重复元素 只会删除连续重复的
	l.unique();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789678
	}
	cout << endl;

	l.push_front(7);
	l.push_front(7);
	l.push_back(8);
	l.push_back(8);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//7778967888
	}
	cout << endl;

	l.unique();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789678
	}
	cout << endl;

	//删除所有小于前者的元素
	l.unique(func2);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";		//789
	}
	cout << endl;

	//删除所有元素
	l.clear();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

bool greaterThan(int val, int val2)
{
	return val > val2;
}

void test5()
{
	list<int> l;

	//判断列表是否为空
	if (l.empty())
	{
		cout << "is empty" << endl;
	}

	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	l.insert(l.begin(), arr, arr + 9);

	//返回最后一个元素
	cout << l.back() << endl;	//9

	//返回第一个元素
	cout << l.front() << endl;	//1

	//最大元素容量(上限)
	cout << l.max_size() << endl;

	//list中当前元素个数
	cout << l.size() << endl;	//9

	//改变元素个数
	l.resize(5);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//12345
	}
	cout << endl;
	cout << l.size() << endl;	//5

	//扩充部分用1来初始化
	l.resize(10, 1);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1234511111
	}
	cout << endl;
	cout << l.size() << endl;	//10

	//排序	默认升序 可以使用谓词改变
	l.sort();
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1111112345
	}
	cout << endl;

	//降序
	l.sort(greaterThan);
	for (auto it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5432111111
	}
	cout << endl;

	//合并 必须是两个有序的列表 
	list<int> l2 = { 2,3,4,5,6,6,2,34,5,2 };
	l2.sort();
	l.sort();

	//默认也是升序 要和原本容器顺序相同 合并之后l2为空
	l.merge(l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1 1 1 1 1 1 2 2 2 2 3 3 4 4 5 5 5 6 6 34
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//降序合并同样需要谓词
	l2 = { 5,2,3,4,5,1,2,9 };
	l.sort(greaterThan);
	l2.sort(greaterThan);
	l.merge(l2, greaterThan);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//拼接两个list l2会清空元素
	l2 = { 5,2,3,4,5,1,2,9 };

	//在迭代器位置,插入链表l2
	l.splice(l.begin(), l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;
	cout << l2.size() << endl;	//0

	//在迭代器位置,插入链表l2中迭代器的元素
	l2 = { 5,2,3,4,5,1,2,9 };
	l.splice(l.begin(), l2, l2.begin());
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 5 2 3 4 5 1 2 9 34 9 6 6 5 5 5 5 5 4 4 4 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1
	}
	cout << endl;

	//在迭代器位置,插入列表的一个迭代器区间
	l.clear();
	l = { 2,43,24,1342,4 };
	l2 = { 5,2,3,4,5,1,2,9 };

	l.splice(l.begin(), l2, l2.begin(), l2.end());
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;

	//list元素倒转
	l.reverse();
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;

	//交换两个list
	l2 = { 1,4,5,2,5,6,1 };
	l.swap(l2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << " ";	//1 4 5 2 6 1
	}
	cout << endl;

	for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it)
	{
		cout << *it << " ";	//5 2 3 4 5 1 2 9 2 43 24 1342 4
	}
	cout << endl;
}

int main()
{

	return 0;
}